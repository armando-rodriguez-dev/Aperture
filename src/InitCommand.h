#ifndef INIT_COMMAND_H
#define INIT_COMMAND_H

#include <string>

bool doesGitDirectoryExist();

bool isCurrentGitDirectoryValid();

void createGitDirectory(std::string &currentWorkingDirectory);


#endif