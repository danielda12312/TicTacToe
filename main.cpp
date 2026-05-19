#include<iostream>
#include<vector>

void printGameBoard(const std::vector<std::vector<char>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    bool gameLoop = true;
    int test = 5/3;
    std::cout << test << "\n";
    while (gameLoop) {
        std::cout << "##################\n";
        std::cout << "# 1. Start Game #\n";
        std::cout << "# 2. Exit       #\n";
        std::cout << "##################\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::vector<std::vector<char>> gameBoard(3, std::vector<char>(3, ' '));
        bool player1turn;
        switch (choice) {
        case 1: {
            std::cout << "Starting the game...\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    gameBoard[i][j] = '1' + i * 3 + j;
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << gameBoard[i][j] << " ";
                }
                std::cout << "\n";
            }

            std::cout << "Player 1's turn. Enter your position (1-9): ";
            int player1Position;
            std::cin >> player1Position;
            player1turn = true;

            while (player1turn) {
                if (player1Position >= 1 && player1Position <= 9) {
                    int row = (player1Position - 1) / 3;
                    int col = (player1Position - 1) % 3;
                    gameBoard[row][col] = 'X';
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            std::cout << gameBoard[i][j] << " ";
                        }
                        std::cout << "\n";
                        player1turn = false;
                    }
                } else {
                    std::cout << "Invalid position. Please enter a number between 1 and 9.\n";
                }
            }
            break;
        }
        case 2:
            std::cout << "Exiting the game. Goodbye!\n";
            gameLoop = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
