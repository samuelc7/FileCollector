/**
 * @file FileReader.h
 * @author Samuel Cummings
 * @brief Opens the passed in files, finds the include statements 
 *          and stores the include statements with their origin
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FILE_READER_H
#define FILE_READER_H

#include <filesystem>
#include <vector>
#include <map>
#include <string> 
namespace fs = std::filesystem;
/**
 * @brief The FileReader takes in a vector of file paths, 
 *          opens the files, and stores all of the included libraries
 *          with the location they were found.
 */
class FileReader {
    public: 
        FileReader(std::vector<fs::path> f) { files = f; findIncludes(); }
    private:
        std::vector<fs::path> files;
        std::map<std::string, std::vector<fs::path>> includes;
        /**
         * @brief This iterates through the paths vector, opens each file, 
         *          parses the header of each file to locate the include statements, 
         *          stores the include statements in the includes tuple with the
         *          location of the file that contained it.
         */
        void findIncludes();
};

#endif