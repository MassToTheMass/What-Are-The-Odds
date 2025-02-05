// Include necessary libraries for input/output, vector operations, string manipulation, time, and random number generation
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

// Define a structure to represent a dare, which consists of a description and a probability
struct Dare {
    // Description of the dare
    std::string description;
    // Probability of the dare being chosen (higher values mean lower probability)
    int probability;
};

// Function to get the difficulty name based on the probability
// This function takes an integer probability as input and returns a string representing the difficulty level
std::string getDifficultyName(int probability) {
    // Use a switch statement to map probability values to difficulty names
    switch (probability) {
        // If the probability is 10, return "Easy"
        case 10:
            return "Easy";
        // If the probability is 25, return "Medium"
        case 25:
            return "Medium";
        // If the probability is 50, return "Hard"
        case 50:
            return "Hard";
        // If the probability is 75, return "Extreme"
        case 75:
            return "Extreme";
        // If the probability is 100, return "Diabolical"
        case 100:
            return "Diabolical";
        // If the probability is not recognized, return an empty string
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
// This function prints the difficulty menu options to the console
void displayDifficultyMenu() {

    std::cout << "Select a difficulty level:" << std::endl;

    std::cout << "-------------------------------" << std::endl;

    std::cout << "1. Easy (1/10)" << std::endl;
    std::cout << "2. Medium (1/25)" << std::endl;
    std::cout << "3. Hard (1/50)" << std::endl;
    std::cout << "4. Extreme (1/75)" << std::endl;
    std::cout << "5. Diabolical (1/100)" << std::endl;
    // Prompt the user to enter their choice
    std::cout << "Enter your choice: ";
}

// Function to display the dare selection menu
// This function takes a vector of dares as input and prints the selected dare to the console
void displayDareMenu(const std::vector<Dare>& dares) {
    // Print a message indicating the selected difficulty level
    std::cout << "You have chosen the " << getDifficultyName(dares[0].probability) << " difficulty level." << std::endl;
    // Print a message indicating the selected dare
    std::cout << "Here is your dare:" << std::endl;
    // Print the description of the selected dare
    std::cout << dares[0].description << std::endl;
    // Print the odds of the selected dare
    std::cout << "The odds are: 1/" << dares[0].probability << std::endl;
}

// Function to get a random dare from the given vector
// This function takes a vector of dares as input and returns a random dare
Dare getRandomDare(const std::vector<Dare>& dares) {
    // Use the rand function to generate a random index into the vector
    // The rand function generates a random integer between 0 and RAND_MAX
    // We use the modulo operator to ensure the index is within the bounds of the vector
    return dares[rand() % dares.size()];
}

// Function to play the game
// This function takes a vector of dares as input and plays the game
void playGame(const std::vector<Dare>& dares) {
    // Declare a variable to store the user's difficulty choice
    int difficulty;
    // Display the difficulty menu
    displayDifficultyMenu();
    // Read the user's difficulty choice from the console
    std::cin >> difficulty;

    // Declare a vector to store the dares that match the user's difficulty choice
    std::vector<Dare> selectedDares;
    // Use a switch statement to filter the dares based on the user's difficulty choice
    switch (difficulty) {
        // If the user chose Easy, select dares with a probability of 10
        case 1:
            for (const auto& dare : dares) {
                if (dare.probability == 10) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        // If the user chose Medium, select dares with a probability of 25
        case 2:
            for (const auto& dare : dares) {
                if (dare.probability == 25) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        // If the user chose Hard, select dares with a probability of 50
        case 3:
            for (const auto& dare : dares) {
                if (dare.probability == 50) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        // If the user chose Extreme, select dares with a probability of 75
        case 4:
            for (const auto& dare : dares) {
                if (dare.probability == 75) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        // If the user chose Diabolical, select dares with a probability of 100
        case 5:
            for (const auto& dare : dares) {
                if (dare.probability == 100) {
                    selectedDares.push_back(dare);
                }
            }
            break;
        // If the user entered an invalid difficulty choice, print an error message and return
        default:
            std::cout << "Invalid difficulty level." << std::endl;
            return;
    }

    // Get a random dare from the selected dares
    Dare selectedDare = getRandomDare(selectedDares);

    // Display the dare selection menu
    displayDareMenu({selectedDare});

    // Declare a variable to store the user's number
    int userNumber;
    // Prompt the user to enter a number between 1 and the probability of the selected dare
    std::cout << "Enter a number between 1 and " << selectedDare.probability << ": ";
    // Read the user's number from the console
    std::cin >> userNumber;

    // Check if the user's number is within the valid range
    if (userNumber < 1 || userNumber > selectedDare.probability) {
        // If the number is not valid, print an error message and return
        std::cout << "Invalid number." << std::endl;
        return;
    }

    // Seed the random number generator with the current time
    srand(time(0));
    // Generate a random number between 1 and the probability of the selected dare
    int computerNumber = rand() % selectedDare.probability + 1;

    // Print the computer's number
    std::cout << "The computer has chosen: " << computerNumber << std::endl;

    // Check if the user's number matches the computer's number
    if (userNumber == computerNumber) {
        // If the numbers match, print a message indicating that the user must do the dare
        std::cout << "You have to do the dare!" << std::endl;
    } else {
        // If the numbers do not match, print a message indicating that the user does not have to do the dare
        std::cout << "You don't have to do the dare." << std::endl;
    }
}

// Main function
int main() {
    // Declare a vector to store the dares
    std::vector<Dare> dares = {
        // List of dares with their descriptions and probabilities
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

    // Declare a variable to store the user's choice
    int choice;
    // Use a do-while loop to repeatedly display the main menu and play the game until the user chooses to exit
    do {
        // Display the main menu
        displayMenu();
        // Read the user's choice from the console
        std::cin >> choice;

        // Use a switch statement to handle the user's choice
        switch (choice) {
            // If the user chose to play the game, call the playGame function
            case 1:
                playGame(dares);
                break;
            // If the user chose to exit, print a message and break out of the loop
            case 2:
                std::cout << "Exiting the game." << std::endl;
                break;
            // If the user entered an invalid choice, print an error message
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 2);

    // Return 0 to indicate successful execution
    return 0;
}
