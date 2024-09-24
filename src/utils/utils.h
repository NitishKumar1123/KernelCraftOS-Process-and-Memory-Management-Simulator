#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Utility functions for string manipulation
std::vector<std::string> split(const std::string& str, char delimiter);
std::string trim(const std::string& str);
std::string toUpperCase(const std::string& str);

#endif // UTILS_H
