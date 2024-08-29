#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

void numberGuessingGame() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0))); 

    // Generate random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess what it is?" << std::endl;

    // Loop until the user guesses correctly
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number " << numberToGuess 
                      << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }
}

int main() {
    numberGuessingGame();
    return 0;
}