/**
 * @file FileCollector.h
 * @author Samuel Cummings
 * @brief Finds all cpp and header files in the given directory
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FILE_COLLECTOR_H
#define FILE_COLLECTOR_H

#include <filesystem>
#include <vector>
#include <regex>

namespace fs = std::filesystem;
/**
 * @brief The FileCollector takes in a root path and finds and collects
 *          all of the locations of each cpp and header file within all 
 *          the subdirectories. 
 */
class FileCollector {
    public: 
        FileCollector(fs::path rootPath) { 
            root = rootPath; 
            recursiveFileFinder(root); 
        }
        /**
         * @brief Gets all of the files found. 
         * @return * std::vector<fs::path> const 
         */
        std::vector<fs::path> const getFilePaths() { return allFilePaths; }
        /**
         * @brief Displays the file locations and count of files found.
         */
        void display();
    private: 
        fs::path root;
        std::vector<fs::path> allFilePaths{};
        std::regex searchPattern{".cpp|.cc|.C|.CPP|.c++|.cp|.cxx|.h|.hpp|.H"};
        /**
         * @brief Recursive function that adds file paths to the allFilePaths if 
         *          they match the search pattern (if they are cpp or header files.)
         *          Is recalled each time a new directory is found.
         * 
         * @param currentPath - The current path being searched. 
         */
        void recursiveFileFinder(fs::path currentPath);
};
#endif