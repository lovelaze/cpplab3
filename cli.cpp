#include "cli.h"
#include "character.h"
#include "env.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "common.h"
#include "food.h"
#include "cli_help.cpp"


using namespace std;
using namespace adventure;


Cli::Cli() {

    commands["go"] = &Cli::go;
    commands["take"] = &Cli::take;
    commands["help"] = &Cli::help;
    commands["drop"] = &Cli::drop;
    commands["backpack"] = &Cli::backpack;
    commands["map"] = &Cli::map;
    commands["fight"] = &Cli::fight;
    commands["items"] = &Cli::items;
    commands["characters"] = &Cli::characters;
    commands["stats"] = &Cli::stats;
    commands["eat"] = &Cli::eat;
    commands["talk"] = &Cli::talk;

}

Cli::~Cli() {
    // Deconstructing stuff fredrik style
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

    if(valid_command(cmd))
        (this->*(this->commands[cmd]))(tokens, c);
    else
        cout << "no such command" << endl;
}