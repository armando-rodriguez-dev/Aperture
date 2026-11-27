#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

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
    const std::filesystem::path refsFolderPath = currentPath / std::filesystem::path("refs");
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

void createApertureDirectory(const std::filesystem::path &currentWorkingDirectory) {
    std::filesystem::path apertureRoot = currentWorkingDirectory / ".aperture";     //folder

    std::filesystem::path headFileInApertureRoot = apertureRoot / "HEAD";           //file
    std::filesystem::path indexFile = apertureRoot / "index";                       //file

    std::filesystem::path logsFolder = apertureRoot / "logs";                       //folder
    std::filesystem::path headFileInLogsFolder = logsFolder / "HEAD";               //file

    std::filesystem::path objectsFolder = apertureRoot / "objects";                 //folder
    std::filesystem::path refsFolder = apertureRoot / "refs";                       //folder
    std::filesystem::path headsFolderInRefs = refsFolder / "heads";                 //folder

    std::filesystem::create_directory(apertureRoot);
    std::filesystem::create_directory(logsFolder);
    std::filesystem::create_directory(objectsFolder);
    std::filesystem::create_directory(refsFolder);
    std::filesystem::create_directory(headsFolderInRefs);

    std::ofstream{headFileInApertureRoot};
    std::ofstream{indexFile};
    std::ofstream{headFileInLogsFolder};
}

void reinitializeApertureDirectory(const std::filesystem::path &currentWorkingDirectory) {
    //check the folders and files and create whichever ones ar missing.
    std::filesystem::path apertureRoot = currentWorkingDirectory / ".aperture";     //folder

    std::filesystem::path headFileInApertureRoot = apertureRoot / "HEAD";           //file
    std::filesystem::path indexFile = apertureRoot / "index";                       //file

    std::filesystem::path logsFolder = apertureRoot / "logs";                       //folder
    std::filesystem::path headFileInLogsFolder = logsFolder / "HEAD";               //file

    std::filesystem::path objectsFolder = apertureRoot / "objects";                 //folder
    std::filesystem::path refsFolder = apertureRoot / "refs";                       //folder
    std::filesystem::path headsFolderInRefs = refsFolder / "heads";                 //folder

    //do folders exist
    if(!doesFolderExistInCurrentDirectory(apertureRoot, "logs")) {
        std::filesystem::create_directory(logsFolder);
    }

    if(!doesFolderExistInCurrentDirectory(apertureRoot, "objects")) {
        std::filesystem::create_directory(objectsFolder);
    }

    if(!doesFolderExistInCurrentDirectory(apertureRoot, "refs")) {
        std::filesystem::create_directory(refsFolder);
    }

    if(!doesFolderExistInCurrentDirectory(refsFolder, "heads")) {
        std::filesystem::create_directory(headsFolderInRefs);
    }

    //do files exist
    if(!doesFileExistInCurrentDirectory(apertureRoot, "HEAD")) {
        std::ofstream{headFileInApertureRoot};
    }

    if(!doesFileExistInCurrentDirectory(apertureRoot, "index")) {
        std::ofstream{indexFile};
    }

    if(!doesFileExistInCurrentDirectory(logsFolder, "HEAD")) {
        std::ofstream{headFileInLogsFolder};
    }
}   