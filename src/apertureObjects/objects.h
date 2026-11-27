#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <filesystem>
#include <iostream>
#include <vector>

//view object type -> "git cat-file -t <full-hash>"
//view object content -> "git cat-file -p <full-hash>"
//view all object hashes and their type -> "git cat-file --batch-all-objects --batch-check='%(objectname) %(objecttype)'""

enum class TreeItemObjectType {
    blob = 0,
    tree = 1
};

enum class FileMode {
    blob = 100644,
    tree = 40000,
    executable = 100755
};

struct TreeItems {
    FileMode mode;
    TreeItemObjectType objectType;
    std::string hash;
    std::string itemName;
};


class Blobs {
    private:
        std::string uniqueBlobHash;

    public:
        Blobs(); //constructor
};

class Trees {
    private:
        std::string uniqueTreeHash;
        std::vector<TreeItems> storedItems;

    public:
        Trees(); //constructor
};

class Commits {
    private:
        std::string uniqueCommitHash;
        std::string parentCommitHash;

        std::string rootTreeHash;
        std::string commitMessage;
    
    public:
        Commits(); //constructor
};

#endif