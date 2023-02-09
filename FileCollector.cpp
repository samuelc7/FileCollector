#include "FileCollector.h"
#include <iostream>

void FileCollector::recursiveFileFinder(fs::path currentPath) {
     // Find same level files
    for (auto const & entry : fs::directory_iterator(currentPath)) {
        if (entry.is_regular_file()) {
            if (std::regex_match(entry.path().filename().extension().c_str(), searchPattern)) {
                allFilePaths.push_back(entry.path());
            }
        }
    }
    // Get same level directories
    for (auto const & entry : fs::directory_iterator(currentPath)) {
        if (entry.is_directory()) {
            if(entry.path().filename().c_str()[0] != '.') {
                // Repeat
                recursiveFileFinder(entry.path());
            }
        }
    }
}

void FileCollector::display() {
    std::cout << "Files found: \n";
    for (auto const &p : allFilePaths) {
        std::cout << p;
    }
    std::cout << "File count: " << allFilePaths.size() << '\n';
}