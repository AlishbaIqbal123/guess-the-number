#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));
    
    // Game configuration
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    const int MAX_ATTEMPTS = 7;
    
    // Generate random number between MIN_NUMBER and MAX_NUMBER
    int secretNumber = rand() % MAX_NUMBER + MIN_NUMBER;
    
    int guess;
    int attempts = 0;
    bool hasWon = false;
    
    cout << "Welcome to Guess the Number Game!\n";
    cout << "I'm thinking of a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
    cout << "You have " << MAX_ATTEMPTS << " attempts to guess it.\n\n";
    
    // Game loop
    while (attempts < MAX_ATTEMPTS) {
        cout << "Attempt " << (attempts + 1) << "/" << MAX_ATTEMPTS << ": Enter your guess: ";
        
        // Input validation
        if (!(cin >> guess)) {
            cout << "Please enter a valid number!\n";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            continue;
        }
        
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Too low! ";
        } else if (guess > secretNumber) {
            cout << "Too high! ";
        } else {
            hasWon = true;
            break;
        }
        
        // Show remaining attempts
        cout << "You have " << (MAX_ATTEMPTS - attempts) << " attempts left.\n\n";
    }
    
    // Game result
    if (hasWon) {
        cout << "\nCongratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!\n";
    } else {
        cout << "\nGame over! The number was " << secretNumber << ". Better luck next time!\n";
    }
    
    return 0;
}