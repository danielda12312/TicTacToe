#include<iostream>
#include<vector>
void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
    std::cout << "\n";
}

void printGameBoard(const std::vector<std::vector<char>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

void playerMove(std::vector<std::vector<char>>& gameBoard, char playerSymbol) {
    std::cout << "Player " << playerSymbol << "'s turn. Enter your position (1-9): ";
    int position;
    std::cin >> position;
    while (position < 1 || position > 9) {
        std::cout << "Invalid position. Please enter a number between 1 and 9.\n";
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        }
        playerMove(gameBoard, playerSymbol);
        return;
    }
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O') {
        gameBoard[row][col] = playerSymbol;
    } else {
        std::cout << "Position already taken. Please try again.\n";
        playerMove(gameBoard, playerSymbol);
    }
}

void checkForWinner(const std::vector<std::vector<char>>& gameBoard, char playerSymbol) {
    // Check rows
    for (const auto& row : gameBoard) {
        if (row[0] == playerSymbol && row[1] == playerSymbol && row[2] == playerSymbol) {
            std::cout << "Player " << playerSymbol << " wins!\n";
            exit(0);
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (gameBoard[0][col] == playerSymbol && gameBoard[1][col] == playerSymbol && gameBoard[2][col] == playerSymbol) {
            std::cout << "Player " << playerSymbol << " wins!\n";
            exit(0);
        }
    }

    // Check diagonals
    if (gameBoard[0][0] == playerSymbol && gameBoard[1][1] == playerSymbol && gameBoard[2][2] == playerSymbol) {
        std::cout << "Player " << playerSymbol << " wins!\n";
        exit(0);
    }
    if (gameBoard[0][2] == playerSymbol && gameBoard[1][1] == playerSymbol && gameBoard[2][0] == playerSymbol) {
        std::cout << "Player " << playerSymbol << " wins!\n";
        exit(0);
    }
}

void checkForDraw(const std::vector<std::vector<char>>& gameBoard) {
    for (const auto& row : gameBoard) {
        for (const auto& cell : row) {
            if (cell != 'X' && cell != 'O') {
                return; // Not a draw, there are still empty cells
            }
        }
    }
    std::cout << "It's a draw!\n";
    exit(0);
}



int main() {

    bool winner = false;
    bool gameLoop = true;

    std::cout << "##################\n";
    std::cout << "# 1. Start Game #\n";
    std::cout << "# 2. Exit       #\n";
    std::cout << "##################\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    std::vector<std::vector<char>> gameBoard(3, std::vector<char>(3, ' '));
    bool player1turn;
    bool player2turn;
    
    while (gameLoop) {
        
        switch (choice) {
        case 1: {
            std::cout << "Starting the game...\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    gameBoard[i][j] = '1' + i * 3 + j;
                }
            }

            clearConsole();
            printGameBoard(gameBoard);

            player1turn = true;
            player2turn = false;

            while (winner == false) {
                if (player1turn) {
                    playerMove(gameBoard, 'X');
                    checkForWinner(gameBoard, 'X');
                    player1turn = false;
                } else {
                    playerMove(gameBoard, 'O');
                    checkForWinner(gameBoard, 'O');
                    player1turn = true;
                }
                clearConsole();
                
                printGameBoard(gameBoard);
                checkForDraw(gameBoard);
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
