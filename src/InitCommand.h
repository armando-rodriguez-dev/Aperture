#ifndef INIT_COMMAND_H
#define INIT_COMMAND_H



bool doesGitDirectoryExist();

bool isCurrentGitDirectoryValid(std::string &currentWorkingDirectory);

void createGitDirectory(std::string &currentWorkingDirectory);


#endif