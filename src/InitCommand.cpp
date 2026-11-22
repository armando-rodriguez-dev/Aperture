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

bool isCurrentApertureFolderValid(const std::string &currentPath) {
    const bool missingRequiredRootFiles =
        !doesFileExistInCurrentDirectory(currentPath, "COMMIT_EDITMSG") ||
        !doesFileExistInCurrentDirectory(currentPath, "HEAD") ||
        !doesFileExistInCurrentDirectory(currentPath, "index");

    if (missingRequiredRootFiles) {
        return false;
    }

    const bool missingRequiredRootFolders =
        !doesFolderExistInCurrentDirectory(currentPath, "logs") ||
        !doesFolderExistInCurrentDirectory(currentPath, "objects") ||
        !doesFolderExistInCurrentDirectory(currentPath, "refs");

    if (missingRequiredRootFolders) {
        return false;
    }

    // Check for required subfolders and files in folders
    const std::string refsFolderPath = currentPath + "/refs";
    const std::string logsFolderPath = currentPath + "/logs";

    const bool missingHeadsSubfolder =
        !doesFolderExistInCurrentDirectory(refsFolderPath, "heads");

    const bool missingHEADFile =
        !doesFileExistInCurrentDirectory(refsFolderPath, "HEAD");

    if (missingHEADFile || missingHeadsSubfolder) {
        return false;
    }

    return true;
}

void createApertureDirectory(std::string &currentWorkingDirectory) {
   /** all in the .aperture folder
            ├── COMMIT_EDITMSG       (file)
            ├── HEAD                 (file)
            ├── index                (binary file)
            ├── logs/                (folder)
            │   └── HEAD             (text file) in a subfolder
            ├── objects/             (folder)
                └── stores the objects the were compressed
            └── refs/                (folder)
                └── heads/           (subfolder, still a folder)
                    └── stores the hashes of the heads of each of the 
*/

}




