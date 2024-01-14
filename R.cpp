#include <iostream>
#include <cstdlib>
#include <ctime>

enum class Choice {
    ROCK,
    PAPER,
    SCISSORS
};

Choice getUserChoice() {
    int choice;
    std::cout << "Choose your move:\n"
              << "1. Rock\n"
              << "2. Paper\n"
              << "3. Scissors\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            return Choice::ROCK;
        case 2:
            return Choice::PAPER;
        case 3:
            return Choice::SCISSORS;
        default:
            std::cout << "Invalid choice. Please choose again.\n";
            return getUserChoice();
    }
}

Choice getComputerChoice() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNum = rand() % 3 + 1;  // Generates a random number between 1 and 3

    switch (randomNum) {
        case 1:
            return Choice::ROCK;
        case 2:
            return Choice::PAPER;
        case 3:
            return Choice::SCISSORS;
        default:
            return Choice::ROCK;  // Default to rock in case of unexpected error
    }
}

void determineWinner(Choice user, Choice computer) {
    std::cout << "You chose ";
    switch (user) {
        case Choice::ROCK:
            std::cout << "Rock";
            break;
        case Choice::PAPER:
            std::cout << "Paper";
            break;
        case Choice::SCISSORS:
            std::cout << "Scissors";
            break;
    }

    std::cout << ". Computer chose ";
    switch (computer) {
        case Choice::ROCK:
            std::cout << "Rock";
            break;
        case Choice::PAPER:
            std::cout << "Paper";
            break;
        case Choice::SCISSORS:
            std::cout << "Scissors";
            break;
    }

    std::cout << ". ";

    // Determine the winner
    if (user == computer) {
        std::cout << "It's a tie!\n";
    } else if ((user == Choice::ROCK && computer == Choice::SCISSORS) ||
               (user == Choice::PAPER && computer == Choice::ROCK) ||
               (user == Choice::SCISSORS && computer == Choice::PAPER)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

int main() {
    std::cout << "Welcome to Rock, Paper, Scissors!\n";

    while (true) {
        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            std::cout << "Thanks for playing. Goodbye!\n";
            break;
        }
    }

    return 0;
}
