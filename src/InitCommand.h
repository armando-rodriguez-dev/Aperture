#ifndef INIT_COMMAND_H
#define INIT_COMMAND_H

#include <filesystem>


bool doesApertureFolderExist();

bool doesFileExistInCurrentDirectory(const std::filesystem::path &currentPath, const std::filesystem::path &fileName);

bool doesFolderExistInCurrentDirectory(const std::filesystem::path &currentPath, const std::filesystem::path &folderName);

bool isCurrentApertureFolderValid(const std::filesystem::path &currentPath);

void createApertureDirectory(const std::filesystem::path &currentWorkingDirectory);

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

#endif