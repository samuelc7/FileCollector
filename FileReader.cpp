#include "FileReader.h"
#include <fstream> 
#include <iostream>
#include <regex>

void FileReader::findIncludes() {
    std::regex searchPattern("#include \".*\"$");
    std::ifstream fin;
    for (auto const & path : files) {
        std::vector<std::string> lines;
        std::string line; 

        fin.open(path);
        while (getline(fin, line)){
            if (std::regex_match(line, searchPattern)) {
                lines.push_back(line + '\n');
            }
        }
        fin.close();
        for (auto const & l : lines) {
            if (includes.find(l) != includes.end()) {
                includes[l].push_back(path);
            } else {
                includes[l] = std::vector{path};
            }
        }
    }

    for (auto const &[library, sources] : includes) {
        std::cout << "Library/Package: " << library;
        std::cout << "Sources: \n";
        for (auto s : sources) {
            std::cout << "- " << s << '\n';
        }
        std::cout << '\n';
    }
}