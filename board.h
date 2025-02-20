#pragma once
#include <iostream>
#include <vector>

class Board {
private:
	std::vector<std::vector<int>> grid;
	int size;
	int score;

public:
	Board(int n = 4);
	void spawnTile();
	bool move(int direction);
	bool canMove() const;
	void printBoard() const;
};