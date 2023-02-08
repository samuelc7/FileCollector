/**
 * @file main.cpp
 * @author Samuel Cummings
 * @brief This is the main entry point of the FileCollector project.
 *          The FileCollector takes in a root path and finds and collects
 *          all of the locations of each cpp and header file within all 
 *          the subdirectories. 
 *          This is just a proof of concept for the time being. Eventually,
 *          the FileCollector will contribute to finding all of the packages
 *          a c++ project uses for SBOM purposes.
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <regex>

std::vector<std::filesystem::path> getFilePaths(std::filesystem::path root);
void recursiveFileFinder(std::filesystem::path currentPath, std::vector<std::filesystem::path> *allFilePaths);

int main() {
    std::filesystem::path rootPath;
    std::cout << "Welcome to the FileCollector application.\nPlease enter the root of the C++ project: ";
    std::cin >> rootPath;

    std::vector<std::filesystem::path> filePaths = getFilePaths(rootPath);
}
/**
 * @brief Sets up the files vector and calls the recursive function.
 * 
 * @param root 
 * @return std::vector<std::filesystem::path> - All the file paths found
 */
std::vector<std::filesystem::path> getFilePaths(std::filesystem::path root) {
    std::vector<std::filesystem::path> allFilePaths;

    recursiveFileFinder(root, &allFilePaths); 

    std::cout << "All Files: \n";
    for (auto const &i : allFilePaths) {
        std::cout << i << '\n';
    }

    std::cout << "File count: " << allFilePaths.size() << '\n';
    return allFilePaths;
}
/**
 * @brief Recursive function that adds file paths to the passed in vector if 
 *          they match the search pattern (if they are cpp or header files.)
 *          Is recalled each time a new directory is found. 
 * 
 * @param currentPath - the current path 
 * @param allFilePaths - the vector of all the cpp/header files found
 */
void recursiveFileFinder(std::filesystem::path currentPath, std::vector<std::filesystem::path> *allFilePaths) {
     std::regex searchPattern(".cpp|.cc|.C|.CPP|.c++|.cp|.cxx|.h|.hpp|.H");
    // Find same level files
    for (auto const & entry : std::filesystem::directory_iterator(currentPath)) {
        if (entry.is_regular_file()) {
            if (std::regex_match(entry.path().filename().extension().c_str(), searchPattern)) {
                allFilePaths->push_back(entry.path());
            }
        }
    }
    // Get same level directories
    for (auto const & entry : std::filesystem::directory_iterator(currentPath)) {
        if (entry.is_directory()) {
            if(entry.path().filename().c_str()[0] != '.') {
                // Repeat
                recursiveFileFinder(entry.path(), allFilePaths);
            }
        }
    }
}