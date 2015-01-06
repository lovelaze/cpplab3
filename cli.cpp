#include "cli.h"
#include "character.h"
#include "env.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "common.h"



using namespace std;

vector<string> valid_commands = {"go", "take", "drop", "directions", "fight", "talk", "backpack"};
vector<string> valid_directions = {"north", "east", "south", "west"};

bool adventure::valid_command(std::string cmd) {
    return find(valid_commands.begin(), valid_commands.end(), cmd) != valid_commands.end();
}

bool adventure::valid_direction(std::string input1, std::string input2) {
    bool first = find(valid_directions.begin(), valid_directions.end(), input1) != valid_directions.end();

    bool second;
    if (input1 == "west" || input1 == "east") {
        second = input2 == "";
    } else if (first) {
        second = input2 == "west" || input2 == "east" || input2 == "";
    }

    return first && second;
}

std::string adventure::get_input() {

    std::string s;
    cout << "> ";
    std::getline(std::cin, s);
    return s;

}

void adventure::parse_input(std::string input, Character * c) {

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


        } else if(cmd == "directions") {
            cout << c->current_room_->directions();
        } else if(cmd == "fight") {
            if (tokens.size() == 2) {

                Character * cp = c->current_room_->find_character(tokens[1]);

                if (cp != nullptr) {
                    c->fight(cp);
                    cp->fight(c);
                } else {
                    cout << "could not find " << tokens[1] << " in this room" << endl;
                }
            } else {
                cout << "not a valid character" << endl;
            }

        } else if(cmd == "talk") {
            if (tokens.size() == 2) {
                Character * cp = c->current_room_->find_character(tokens[1]);
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

                Item * ip = c->current_room_->find_item(tokens[1]);

                if (ip != nullptr) {
                    c->pick_up(ip);
                    cout << c->name() << " picked up " << ip ->name() << endl;
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
                        c->backpack()->remove(ip);
                        cout << c->name() << " dropped " << ip->name() << endl;
                    } else {
                        cout << "could not find " << tokens[1] << endl;
                    }
                }
            } else {
                cout << "invalid item" << endl;
            }

        }
    } else {
        cout << "no such command" << endl;
    }










}