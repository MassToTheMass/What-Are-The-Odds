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

// Function to get the difficulty name based on the probability
std::string getDifficultyName(int probability) {
    switch (probability) {
        case 10:
            return "Easy";
        case 25:
            return "Medium";
        case 50:
            return "Hard";
        case 75:
            return "Extreme";
        case 100:
            return "Diabolical";
        default:
            return "";
    }
}

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
    std::cout << "1. Easy (1/10)" << std::endl;
    std::cout << "2. Medium (1/25)" << std::endl;
    std::cout << "3. Hard (1/50)" << std::endl;
    std::cout << "4. Extreme (1/75)" << std::endl;
    std::cout << "5. Diabolical (1/100)" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to display the dare selection menu
void displayDareMenu(const std::vector<Dare>& dares) {
    std::cout << "You have chosen the " << getDifficultyName(dares[0].probability) << " difficulty level." << std::endl;
    std::cout << "Here is your dare:" << std::endl;
    std::cout << dares[0].description << std::endl;
    std::cout << "The odds are: 1/" << dares[0].probability << std::endl;
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
                if (dare.probability == 10) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 2:
            for (const auto& dare : dares) {
                if (dare.probability == 25) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 3:
            for (const auto& dare : dares) {
                if (dare.probability == 50) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 4:
            for (const auto& dare : dares) {
                if (dare.probability == 75) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        case 5:
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

    Dare selectedDare = getRandomDare(selectedDares);

    displayDareMenu({selectedDare});

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
        {"Skinny dip the nearest pond", 50},
        {"Jump in a pool fully clothed", 50},
        {"Lick someones toes", 50},
        {"Kiss a stranger", 50},
        {"Run a 5k", 50},
        {"Complete Sprite and Banana Challenge", 50},
        {"Shotgun Gingerale", 10},
        {"Kiss someones mother", 25},
        {"Crawl a lap around the school", 10},
        {"Ask a random person on a date until they say yes, then go on the date", 25},
        {"Go to a retail store dressed as an employee and work for an hour", 25},
        {"Bring nothing but a hammock and blankets and sleep in the woods for a night", 100},
        {"Polar plunge in 3 rivers in one night (ward canyon, holbrook, and mueller park)", 50},
        {"Do a polar plunge", 25},
        {"Skinny dip a polar plunge", 75},
        {"Hug a deer", 100},
        {"Kiss a horse", 100},
        {"Getting a shot from the med class", 50},
        {"Kiss someone of the same gender", 50},
        {"Wear 3in inseam shorts to school", 100},
        {"Dress like a furry for a day", 75},
        {"Do a 10 minutes stand-up comedy to a large crowd (20+ ppl)", 10},
        {"Ask a random person for water at their house", 50},
        {"Put an eos treadmill to max speed and run until you collapse/fall off", 100},
        {"Sphagetti Kiss", 50}
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
