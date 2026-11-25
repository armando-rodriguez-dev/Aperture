#include <iostream>
#include <string>
#include <array>
#include <filesystem>

#include "InitCommand.h"

bool isValidCommand(const std::string &input, const std::array<std::string, 8> &command);
std::filesystem::path returnProjectRootFolderPath();

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
        std::cerr
            << "error: no commands provided\n"
            << "Usage: aperture <command> [arguments]\n"
            << "Run 'aperture help' for more information\n";

        return 1;
    }

    std::string command = argv[1];

    //Invalid Command
    if(!isValidCommand(command, COMMANDS)) {
        std::cerr
            << "error: '"
            << argv[1]
            << "' is not a valid aperture command\n"
            << "Run 'aperture help' to see available commands\n";
        
          return 1;
    }

    if(command == "init") {
        if(argc > 2) {
            std::cerr << "usage: aperture init \n";
            return 1;
        }

        std::filesystem::path currentPath = returnProjectRootFolderPath();

        //check whether there exists a ".aperture" folder, if none exist create a new one
        if(!doesApertureFolderExist()) {
            createApertureDirectory(currentPath);
            std::cout << "Initialized empty Aperture repository in " << currentPath << "\n";
            return 0;
        }

        //check whether the folder is valid, if not valid then reinitialize the folder
        if(!isCurrentApertureFolderValid(currentPath)) {
            reinitializeApertureDirectory(currentPath);
        } 

        std::cout << "Reinitialized existing Aperture repository in " << currentPath << "\n";
        return 0;
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

// Searches the current directory and its parents for an Aperture project.
std::filesystem::path returnProjectRootFolderPath() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    const std::filesystem::path rootPath = currentPath.std::filesystem::path::root_path();

    while(!doesFolderExistInCurrentDirectory(currentPath, ".aperture")) {
        currentPath = currentPath.std::filesystem::path::parent_path();

        if(currentPath == rootPath) {
            return {};
        }
    }   

    return currentPath;
}

