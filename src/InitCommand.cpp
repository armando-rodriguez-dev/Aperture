#include <filesystem>
#include <string>

#include "InitCommand.h"

bool doesGitDirectoryExist() {
    std::string currentWorkingDirectory = std::filesystem::current_path();
    currentWorkingDirectory = currentWorkingDirectory + "/.aperture";

    return std::filesystem::is_directory(currentWorkingDirectory); 
}

bool isCurrentGitDirectoryValid() {
    //this will check every file and every directory inside of the .git folder for validity

    //things that need to exist

   

}
