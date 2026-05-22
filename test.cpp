#include<iostream>
#include<vector>

void playerMove(std::vector<std::vector<char>>& gameBoard, char playerSymbol) {

    std::cout << "Player " << playerSymbol << "'s turn. Enter your position (1-9): ";
    int position;
    std::cin >> position;

    while (position < 1 || position > 9) {
        std::cout << "Invalid position. Please enter a number between 1 and 9.\n";
        std::cin.clear();
        playerMove(gameBoard, playerSymbol);
        return;
    }

            //rest of function...
    }