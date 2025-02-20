#pragma once
#include "board.h"

class Game {
private:
	Board board;
	bool isGameOver;

public:
	Game();
	void run();
	void processInput(char input);
};