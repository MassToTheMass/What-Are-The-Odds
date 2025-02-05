#include <string>
#include <vector>

class Dare {
    private:
        std::string description;
        int probability;

    public:
        Dare(std::string desc, int prob) : description(desc), probability(prob) {}

        int getProbability() {return probability;}
        std::string getDescription() {return description;}
        void changeDescription() {
            std::cout << "What is the new description: " << std::endl;
            std::string newDescription = "";
            std::getline(std::cin, newDescription);
            description = newDescription;
            std::cout << "Successful" << std::endl;
        }
        int sti(std::string s){
            try {
                int myInt = std::stoi(s);
                // Use myInt
                return myInt;
            } catch (const std::invalid_argument& e) {
                // Handle the case where myString is not a valid integer
                std::cout << "Invalid integer: " << s << std::endl;
            } catch (const std::out_of_range& e) {
                // Handle the case where myString is too large to fit in an int
                std::cout << "Integer out of range: " << s << std::endl;
            }
        }
        void changeProbability() {
            std::cout << "What is the new Probability: " << std::endl;
            std::string newProbability = "";
            std::getline(std::cin, newProbability);
            probability = sti(newProbability);
            std::cout << "Successful" << std::endl;
        }

};