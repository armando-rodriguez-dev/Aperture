#include <filesystem>
#include <string>
#include <iostream>

#include "InitCommand.h"

bool doesFileExistInCurrentDirectory(const std::filesystem::path &currentPath, const std::filesystem::path &fileName) {
    std::filesystem::path targetPath = currentPath / fileName;
        
    return std::filesystem::exists(targetPath);
}

bool doesFolderExistInCurrentDirectory(const std::filesystem::path &currentPath, const std::filesystem::path &folderName) {
    std::filesystem::path targetPath = currentPath / folderName;

    return std::filesystem::is_directory(targetPath);
}

bool doesApertureFolderExist() {
    std::filesystem::path currentWorkingDirectory = std::filesystem::current_path();

    return doesFolderExistInCurrentDirectory(currentWorkingDirectory, ".aperture");
}

bool isCurrentApertureFolderValid(const std::filesystem::path &currentPath) {
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
    const std::filesystem::path refsFolderPath = currentPath /  std::filesystem::path("refs");
    const std::filesystem::path logsFolderPath = currentPath / std::filesystem::path("logs");

    const bool missingHeadsSubfolder =
        !doesFolderExistInCurrentDirectory(refsFolderPath, "heads");

    const bool missingHEADFile =
        !doesFileExistInCurrentDirectory(refsFolderPath, "HEAD");

    if (missingHEADFile || missingHeadsSubfolder) {
        return false;
    }

    return true;
}




