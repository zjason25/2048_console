#include <string>
#include <random>
#include <utility>

#include "board.h"

void Board::initialize()
{
	spawnTile();
	spawnTile();
}

void Board::spawnTile()
{
	std::vector<std::pair<int, int>> emptyCells;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (grid[i][j] == 0) {
				emptyCells.push_back({i, j});
			}
		}
	}
	if (!emptyCells.empty()) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, emptyCells.size() - 1);

		auto [x, y] = emptyCells[dist(gen)];
		std::uniform_int_distribution<int> tileDist(1, 10);
		grid[x][y] = (tileDist(gen) == 1) ? 4 : 2;
	}
}

bool Board::move(int direction)
{
	bool moved = false;
	for (int i = 0; i < size; ++i) {
		std::vector<int> row;

		if (direction == 0 || direction == 1) { // Left or Right
			for (int j = 0; j < size; ++j) {
				if (grid[i][j] != 0) row.push_back(grid[i][j]);
			}
			if (direction == 1) std::reverse(row.begin(), row.end()); // Reverse for Right
		}
		else { // Up or Down
			for (int j = 0; j < size; ++j) {
				if (grid[j][i] != 0) row.push_back(grid[j][i]);
			}
			if (direction == 3) std::reverse(row.begin(), row.end()); // Reverse for Down
		}

		// Merge tiles
		for (size_t j = 0; j + 1 < row.size(); ++j) {
			if (row[j] == row[j + 1]) {
				row[j] *= 2;
				row[j + 1] = 0;
				moved = true;
				j++;
			}
		}

		// Remove zeros and pad
		row.erase(std::remove(row.begin(), row.end(), 0), row.end());
		row.resize(size, 0);

		if (direction == 1 || direction == 3) std::reverse(row.begin(), row.end());

		if ((direction == 0 || direction == 1) && grid[i] != row) {
			grid[i] = row;
			moved = true;
		}
		else if (direction == 2 || direction == 3) {
			for (int j = 0; j < size; ++j) {
				if (grid[j][i] != row[j]) {
					grid[j][i] = row[j];
					moved = true;
				}
			}
		}
	}
	
	if (moved) spawnTile();
	return moved;
}

bool Board::canMove() const
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (grid[i][j] == 0) return true;
			if (j + 1 < size && grid[i][j] == grid[i][j + 1]) return true;
			if (i + 1 < size && grid[i][j] == grid[i + 1][j]) return true;
		}
	}
	return false;
}

void Board::printBoard() const
{
	system("cls");
	std::cout << " --------- --------- --------- --------- \n";
	for (const auto& row : grid) {
		std::cout << "|";
		for (int num : row) {
			std::cout << "    " << (num ? std::to_string(num) : ".") << "    |";
		}
		std::cout << "\n --------- --------- --------- --------- \n";
	}
	
}