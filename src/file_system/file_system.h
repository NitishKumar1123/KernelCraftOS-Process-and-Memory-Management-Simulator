#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <unordered_map>
#include <iostream>

class FileSystem {
public:
    FileSystem();
    void createFile(const std::string& fileName);
    void writeFile(const std::string& fileName, const std::string& data);
    std::string readFile(const std::string& fileName);
    void deleteFile(const std::string& fileName);
    void displayFiles();

private:
    std::unordered_map<std::string, std::string> files; // Maps file name to data
    std::unordered_map<std::string, int> fileSize; // Maps file name to size
};

#endif // FILE_SYSTEM_H