#include <string>
#pragma once


class Dare {
    private:
        std::string description;
        int probability;

    public:
        Dare(std::string desc, int prob) : description(desc), probability(prob) {}

        int getProbability() {return probability;}
        std::string getDescription() {return description;}
};