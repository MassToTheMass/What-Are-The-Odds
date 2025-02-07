#include "dares/dareManager.hpp"
#include <map>
#include <set>
#include <iostream>
#include <fstream>

class Game {

    private:
        std::map<std::string, std::set<Dare>> dare_categories;
        std::vector<std::string> parseString();

    public:
        Game() {
            std::ifstream dare_file_map("dares/mapTextFile.txt");

            if (dare_file_map.is_open()) {
                std::cout << "oppen" << std::endl;
            } else {
                std::cout << "not open";
            }
            std::string line;
            while (std::getline(dare_file_map, line)) {
                std::cout << line << std::endl;
            }
            
        }
};