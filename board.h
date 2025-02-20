#pragma once
#include <iostream>
#include <vector>

class Board {
private:
	std::vector<std::vector<int>> grid;
	int size;

public:
	Board(int n = 4) : size(n), grid(n, std::vector<int>(n, 0)) {}
	void initialize();
	void spawnTile();
	bool move(int direction);
	bool canMove() const;
	void printBoard() const;
};