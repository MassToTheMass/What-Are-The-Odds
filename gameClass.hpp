#include <map>
#include <set>
#include <iostream>
#include <experimental/filesystem>
#include "dares/dareManager.hpp"

namespace fs = std::experimental::filesystem;

class Game {

    private:
        std::map<std::string, std::set<Dare>> dare_categories;
        


    public:
        Game() {
            for (const auto & entry : fs::directory_iterator("dares/dare_text_files")) {
                std::cout << entry << std::endl;
            }
        }
};