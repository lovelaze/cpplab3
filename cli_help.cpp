#include "character.h"
#include "common.h"
#include "cli.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "food.h"
#include "env.h"


using namespace std;

namespace adventure {



    bool Cli::valid_command(std::string cmd) {
        return find(valid_commands.begin(), valid_commands.end(), cmd) != valid_commands.end();
    }

    //==========================================================================

    bool Cli::valid_direction(std::string input1, std::string input2) {
        bool first = find(valid_directions.begin(), valid_directions.end(), input1) != valid_directions.end();

        bool second;
        if (input1 == "west" || input1 == "east") {
            second = input2 == "";
        } else if (first) {
            second = input2 == "west" || input2 == "east" || input2 == "";
        }

        return first && second;
    }

    //==========================================================================
    // FUNCTION POINTER START

    void Cli::go(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {
            if (valid_direction(tokens[1], "")) {
                c->go(direction_to_int(tokens[1], ""));
            }
        } else if (tokens.size() == 3) {
            if (valid_direction(tokens[1], tokens[2])) {
                c->go(direction_to_int(tokens[1], tokens[2]));
            }
        } else {
            cout  << "not a valid direction" << endl;
        }
    }

    //==========================================================================

    void Cli::map(std::vector<std::string> & tokens, Character * c) {
        cout << c->current_room()->directions();
    }

    //==========================================================================

    void Cli::fight(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {

            Character * cp = c->current_room()->find_character(tokens[1]);

            if (cp != nullptr) {
                if (c != cp) {
                    battle(c, cp);
                } else {
                    cout << "can't fight yourself" << endl;
                }

            } else {
                cout << "could not find " << tokens[1] << " in this room" << endl;
            }
        } else {
            cout << "not a valid character" << endl;
        }
    }

    //==========================================================================

    void Cli::talk(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {
            Character * cp = c->current_room()->find_character(tokens[1]);
            if (cp != nullptr) {
                c->talk_to(cp);
            } else {
                cout << "could not find " << tokens[1] << " in this room" << endl;
            }
        } else {
            cout << "not a valid character" << endl;
        }
    }

    //==========================================================================

    void Cli::take(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {

            Item * ip = c->current_room()->find_item(tokens[1]);

            if (ip != nullptr) {
                c->pick_up(ip);

            } else {
                cout << "could not find " << tokens[1] << " in this room" << endl;
            }

        } else {
            cout << "invalid item" << endl;
        }
    }

    //==========================================================================

    void Cli::backpack(std::vector<std::string> & tokens, Character * c) {
        if (c->has_backpack()) {
            c->backpack()->print();
        } else {
            cout << "I have no backpack" << endl;
        }
    }

    //==========================================================================

    void Cli::drop(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {
            if (c->has_backpack()) {

                Item * ip = c->backpack()->find_item(tokens[1]);

                if (ip != nullptr) {
                    c->drop(ip);
                } else {
                    cout << "could not find " << tokens[1] << endl;
                }
            }
        } else {
            cout << "invalid item" << endl;
        }
    }

    //==========================================================================

    void Cli::items(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 1) {
            c->current_room()->printItems();
        } else {
            cout << "invalid command" << endl;
        }
    }

    //==========================================================================

    void Cli::characters(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 1) {
            c->current_room()->printCharacters();
        } else {
            cout << "invalid command" << endl;
        }
    }

    //==========================================================================

    void Cli::stats(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 1) {
            cout << "Health: " << c->health() << "/" << c->max_health() << ", damage: " << c->damage() << endl;
        } else {
            cout << "invalid command" << endl;
        }
    }

    //==========================================================================

    void Cli::eat(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 2) {

            Food * fp = dynamic_cast<Food *>(c->backpack()->find_item(tokens[1]));

            if (fp != nullptr) {
                fp->eat(c);
            } else {
                cout << "could not eat " << tokens[1] << endl;
            }

        } else {
            cout << "What do you want to eat?" << endl;
        }
    }

    //==========================================================================

    void Cli::help(std::vector<std::string> & tokens, Character * c) {
        if (tokens.size() == 1) {
            cout << "Available commands:" << endl;
            for (const std::string & s : valid_commands) {
                cout << s << " ";
            }
            cout << endl;
        } else {
            cout << "invalid command" << endl;
        }
    }

    // FUNCTION POINTER END
    //==========================================================================

    void Cli::battle(Character * c, Character * cp) {
        bool done = false;

        cout << c->name() << " engages " << cp->name() << " in brutal, mortal, combat:" << endl;
        cout << "what do you want to do? (attack, flee)" << endl;
        while (!done && c->alive()) {
            string cmd = get_input();

            if (cmd == "attack") {
                if (c->alive()) {
                    c->fight(cp);
                    if(cp->health() < 20 && cp->alive())
                    if (chance(30)) {
                        done = true;
                        cout << cp->name() << " managed to escape. ";
                        cp->go_to_random_neighbor();
                        continue;

                    }
                } else {
                    done = true;
                }
                if (cp->alive()) {
                    cp->fight(c);
                } else {
                    done = true;

                }

            } else if (cmd == "flee") {
                cout << c->name() << " fled like a sissy-wimp." << endl;
                done = true;
            } else {
                cout << "invalid command" << endl;
            }


        }
    }



}



