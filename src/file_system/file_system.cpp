#include "file_system.h"

FileSystem::FileSystem() {}

void FileSystem::createFile(const std::string& fileName) {
    if (files.find(fileName) != files.end()) {
        std::cerr << "File " << fileName << " already exists.\n";
        return;
    }
    files[fileName] = "";
    fileSize[fileName] = 0;
    std::cout << "File " << fileName << " created.\n";
}

void FileSystem::writeFile(const std::string& fileName, const std::string& data) {
    if (files.find(fileName) == files.end()) {
        std::cerr << "File " << fileName << " does not exist.\n";
        return;
    }
    files[fileName] += data;
    fileSize[fileName] += data.size();
    std::cout << "Data written to file " << fileName << ".\n";
}

std::string FileSystem::readFile(const std::string& fileName) {
    if (files.find(fileName) == files.end()) {
        std::cerr << "File " << fileName << " does not exist.\n";
        return "";
    }
    return files[fileName];
}

void FileSystem::deleteFile(const std::string& fileName) {
    if (files.find(fileName) == files.end()) {
        std::cerr << "File " << fileName << " does not exist.\n";
        return;
    }
    files.erase(fileName);
    fileSize.erase(fileName);
    std::cout << "File " << fileName << " deleted.\n";
}

void FileSystem::displayFiles() {
    std::cout << "Files in system:\n";
    for (const auto& file : files) {
        std::cout << "File Name: " << file.first << ", Size: " << fileSize[file.first] << " bytes\n";
    }
}