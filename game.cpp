#include "game.h"
#include <conio.h>

Game::Game() {
	board = Board();
	isGameOver = false;
}

void Game::run() {
	while (!isGameOver) {
        board.printBoard();
		int key = _getch();
        processInput(key);
	}
}
void Game::processInput(int key) {
    if (key == 224) {
        key = _getch(); // Get second key press if it's an arrow key

        switch (key) {
            case 72: board.move(2); break;
            case 80: board.move(3); break;
            case 75: board.move(0); break;
            case 77: board.move(1); break;
            default: break;
        }
    }
    else {
        switch (key) {
            case 'w': case 'W': board.move(2); break;
            case 's': case 'S': board.move(3); break;
            case 'a': case 'A': board.move(0); break;
            case 'd': case 'D': board.move(1); break;
            case 'q': case 'Q':
                std::cout << "Exiting...\n";
                isGameOver = true;
                return;
            default: break;
        }
    }
}