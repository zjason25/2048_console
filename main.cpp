#include "board.h"
#include <conio.h>

int main()
{
	Board board = Board();
	board.initialize();
	board.printBoard();
    
    while (true) {
        int key = _getch(); // Get first key press
        // If it's an arrow key, _getch() returns 224 first, followed by the actual key code
        if (key == 224) {
            key = _getch(); // Get second key press

            switch (key) {
            case 75: board.move(0); break;
            case 77: board.move(1); break;
            case 72: board.move(2); break;
            case 80: board.move(3); break;
            default: std::cout << "Unknown Key\n"; break;
            }
        }
        board.printBoard();
    }
}