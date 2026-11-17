#include "InitCommand.h"
#include <filesystem>

bool doesGitDirectoryExist() {
    std::string currentWorkingDirectory = std::filesystem::current_path();
    currentWorkingDirectory = currentWorkingDirectory + "/.aperture";

    return std::filesystem::is_directory(currentWorkingDirectory); 
}
