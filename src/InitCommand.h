#ifndef INIT_COMMAND_H
#define INIT_COMMAND_H

#include <string>

bool doesApertureFolderExist();

bool doesFileExistInCurrentDirectory(const std::string &currentPath, const std::string &fileName);

bool doesFolderExistInCurrentDirectory(const std::string &currentPath, const std::string &folderName);

bool isCurrentApertureFolderValid(const std::string &currentPath);

void createApertureDirectory(std::string &currentWorkingDirectory);

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