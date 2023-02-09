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
#include "FileCollector.h"
#include "FileReader.h"

int main() {
    std::filesystem::path rootPath;
    std::cout << "Welcome to the FileCollector application.\nPlease enter the root of the C++ project: ";
    std::cin >> rootPath;

    FileCollector fc = FileCollector{rootPath};     
    FileReader fr  = FileReader{fc.getFilePaths()};
    
    return 0;
}
