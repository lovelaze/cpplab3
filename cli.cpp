#include "cli.h"
#include "character.h"
#include "env.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "common.h"
#include "food.h"



using namespace std;
using namespace adventure;

const vector<string> valid_commands = {"go", "take", "drop", "map", "fight", "talk", "backpack", "items", "chars", "stats", "eat", "help"};
const vector<string> valid_directions = {"north", "east", "south", "west"};

Cli::Cli() {

}

Cli::~Cli() {

}

void Cli::init() {

    inner_map.insert(std::make_pair("go", &Character::go));
}

bool Cli::valid_command(std::string cmd) {
    return find(valid_commands.begin(), valid_commands.end(), cmd) != valid_commands.end();
}

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

std::string Cli::get_input() {

    std::string s;
    cout << "> ";
    std::getline(std::cin, s);
    return s;

}

void Cli::parse_input(std::string input, Character * c) {

    string buf;
    stringstream ss(input);

    vector<string> tokens;

    while (ss >> buf) {
        tokens.push_back(buf);
    }

    if (tokens.size() < 1 || tokens.size() > 3) {
        cout << "wrong input" << endl;
        return;
    }

    string & cmd = tokens[0];
    if (valid_command(cmd)) {


        if (cmd == "go") {
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


        } else if(cmd == "map") {
            cout << c->current_room()->directions();
        } else if(cmd == "fight") {
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

        } else if(cmd == "talk") {
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


        } else if (cmd == "take") {
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


        } else if (cmd == "backpack") {
            if (c->has_backpack()) {
                c->backpack()->print();
            } else {
                cout << "I have no backpack" << endl;
            }
        } else if (cmd == "drop") {
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

        } else if (cmd == "items") {
            if (tokens.size() == 1) {
                c->current_room()->printItems();
            } else {
                cout << "invalid command" << endl;
            }

        } else if (cmd == "chars") {
            if (tokens.size() == 1) {
                c->current_room()->printCharacters();
            } else {
                cout << "invalid command" << endl;
            }
        } else if (cmd == "stats") {
            if (tokens.size() == 1) {
                cout << "Health: " << c->health() << "/" << c->max_health() << ", damage: " << c->damage() << endl;
            } else {
                cout << "invalid command" << endl;
            }
        } else if (cmd == "help") {

            if (tokens.size() == 1) {
                cout << "Available commands:" << endl;
                for (const std::string & s : valid_commands) {
                    cout << s << " ";
                }
                cout << endl;
            } else {
                cout << "invalid command" << endl;
            }
        } else if (cmd == "eat") {
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
    } else {
        cout << "no such command" << endl;
    }


}

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