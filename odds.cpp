#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

// Structure to represent a dare
struct Dare {
    std::string description;
    int probability;
};

// Function to display the main menu
void displayMenu() {
    std::cout << "Welcome to What Are The Odds!" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Play Game" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to display the difficulty menu
void displayDifficultyMenu() {
    std::cout << "Select a difficulty level:" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Easy (1/5)" << std::endl;
    std::cout << "2. Medium (1/10)" << std::endl;
    std::cout << "3. Hard (1/50)" << std::endl;
    std::cout << "4. Extreme (1/100)" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to display the dare selection menu
void displayDareMenu(const std::vector<Dare>& dares) {
    std::cout << "Select a dare:" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < dares.size(); i++) {
        std::cout << i + 1 << ". " << dares[i].description << std::endl;
    }
    std::cout << dares.size() + 1 << ". Random Dare" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to get a random dare from the given vector
Dare getRandomDare(const std::vector<Dare>& dares) {
    return dares[rand() % dares.size()];
}

// Function to play the game
void playGame(const std::vector<Dare>& dares) {
    int difficulty;
    displayDifficultyMenu();
    std::cin >> difficulty;

    std::vector<Dare> selectedDares;
    switch (difficulty) {
        case 1:
            for (const auto& dare : dares) {
                if (dare.probability == 5) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 2:
            for (const auto& dare : dares) {
                if (dare.probability == 10) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 3:
            for (const auto& dare : dares) {
                if (dare.probability == 25) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 4:
            for (const auto& dare : dares) {
                if (dare.probability == 50) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 5:
            for (const auto& dare : dares) {
                if (dare.probability == 75) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 6:
            for (const auto& dare : dares) {
                if (dare.probability == 100) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        default:
            std::cout << "Invalid difficulty level." << std::endl;
            return;
    }

    int dareChoice;
    displayDareMenu(selectedDares);
    std::cin >> dareChoice;

    Dare selectedDare;
    if (dareChoice == selectedDares.size() + 1) {
        selectedDare = getRandomDare(selectedDares);
    } else if (dareChoice > 0 && dareChoice <= selectedDares.size()) {
        selectedDare = selectedDares[dareChoice - 1];
    } else {
        std::cout << "Invalid dare choice." << std::endl;
        return;
    }

    std::cout << "You have chosen: " << selectedDare.description << std::endl;
    std::cout << "The odds are: 1/" << selectedDare.probability << std::endl;

    int userNumber;
    std::cout << "Enter a number between 1 and " << selectedDare.probability << ": ";
    std::cin >> userNumber;

    if (userNumber < 1 || userNumber > selectedDare.probability) {
        std::cout << "Invalid number." << std::endl;
        return;
    }

    srand(time(0));
    int computerNumber = rand() % selectedDare.probability + 1;

    std::cout << "The computer has chosen: " << computerNumber << std::endl;

    if (userNumber == computerNumber) {
        std::cout << "You have to do the dare!" << std::endl;
    } else {
        std::cout << "You don't have to do the dare." << std::endl;
    }
}

int main() {
    // Database of dares
    std::vector<Dare> dares = {
        {"Sing a song in front of everyone", 10},
        {"Do the tism slide in cafe for a minute", 25},
        {"Run around the block", 10},
        {"Sing a song with a mouthful of water", 25},
        {"Eat a ghost pepper", 50},
        {"Do 50 push-ups", 10},
        {"Run a mile", 25},
        {"Go through a drive through shirtless on the hood of your car with the card in your mouth and smooth jazz.", 25},
        {"Run half a mile in a just speedo", 50},
        {"Drink a gallon of milk", 50},
        {"Skinny dip the nearest pond", 75},
        {"Jump in a pool fully clothed", 50},
        {"Lick someones toes", 50},
        {"Kiss a stranger", 50},
        {"Run a 5k", 50},
        {"Complete Sprite and Banana Challenge", 50},
        {"Shotgun Gingerale", 10},
        {"Kiss someones mother", 25},
        {"Crawl a lap around the school", 10},
        {"Ask a random person on a date until they say yes, then go on the date", 25},
        {""}


    };

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                playGame(dares);
                break;
            case 2:
                std::cout << "Exiting the game." << std::endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 2);

    return 0;
}
