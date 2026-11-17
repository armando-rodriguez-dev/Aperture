#include <iostream>
#include <string>
#include <array>
#include <cstdio>

#include "InitCommand.h"

bool isValidCommand(
    const std::string &,
    const std::array<std::string, 8> &
);

const std::array<std::string, 8> COMMANDS = {
    "init",
    "status",
    "add",
    "commit",
    "log",
    "diff",
    "restore",
    "help"
};


int main(int argc, char *argv[]) {
    
    //Not Enough Arguments
    if(argc <= 1) {
        printf("error: no commands provided\n");
        printf("Usage: aperture <command> [arguments]\n");
        printf("Run 'aperture help' for more information\n");

        return 1;
    }

    //Invalid Command
    if(!isValidCommand(argv[1], COMMANDS)) {
        printf("error: '%s' is not a valid aperture command\n", argv[1]);
        printf("Run 'aperture help' to see available commands\n");

        return 1;
    }

    return 0;
}

bool isValidCommand(const std::string &input, const std::array<std::string, 8> &commands) {
    for(std::size_t i = 0; i < commands.size(); i++) {
        if(input == commands[i]) {
            return true;
        }
    }

    return false;
}