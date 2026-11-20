#include <filesystem>
#include <string>
#include <iostream>

#include "InitCommand.h"

bool doesFileExistInCurrentDirectory(const std::string &currentPath, const std::string &fileName) {
    std::string targetPath = currentPath + "/" + fileName;
        
    return std::filesystem::exists(targetPath);
}

bool doesFolderExistInCurrentDirectory(const std::string &currentPath, const std::string &folderName) {
    std::string targetPath = currentPath + "/" + folderName;

    return std::filesystem::is_directory(targetPath);
}

bool doesApertureFolderExist() {
    std::string currentWorkingDirectory = std::filesystem::current_path();

    return doesFolderExistInCurrentDirectory(currentWorkingDirectory, ".aperture");
}

// bool isCurrentApertureFolderValid(const std::string &currentPath) {

//     const bool missingRequiredFiles = 
//         !doesFileExistInCurrentDirectory(currentPath, "COMMIT_EDITMSG") ||
//         !doesFileExistInCurrentDirectory(currentPath, "HEAD") || 
//         !doesFileExistInCurrentDirectory(currentPath, "index");

//     if(missingRequiredFiles){
//         return false;
//     }


// }

/**
    ├── COMMIT_EDITMSG       (file)
    ├── HEAD                 (file)
    ├── index                (binary file)
    ├── logs/
    │   └── HEAD             (text file)
    ├── objects/
        └── stores the objects the were compressed
    └── refs/
        └── heads/
            └── stores the hashes of the heads of each of the 
*/

