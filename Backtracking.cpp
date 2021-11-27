#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "Util.h"
#include "Backtracking.h"

bool is_possible_sudoku(std::vector<std::vector<int>>& grid, int x, int y, int n) {

	for (int j = 0; j < grid.size(); j++)
	{
		if (grid[x][j] == n) {
			return false;
		}
	}

	for (int i = 0; i < grid.size(); i++)
	{
		if (grid[i][y] == n) {
			return false;
		}
	}

	int x0 = (x / 3) * 3;
	int y0 = (y / 3) * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[x0 + i][y0 + j] == n)
			{
				return false;
			}
		}
	}

	return true;

}

bool solve_sudoku(std::vector<std::vector<int>>& grid, int x, int y) {

	if (x == 8 && y == 8) {
		printSequenceSequence(grid);
		//std::this_thread::sleep_for(std::chrono::milliseconds(x));
		return true;
	}
	else {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (grid[i][j] == 0) {
					for (int k = 1; k <= 9; k++)
					{
						if (is_possible_sudoku(grid, i, j, k)) {
							grid[i][j] = k;
							//system("cls");
							//printSequenceSequence(grid);
							//std::this_thread::sleep_for(std::chrono::milliseconds(x));
							solve_sudoku(grid, i, j);
							grid[i][j] = 0;
						}
					}
					return false;
				}

			}
		}
	}

}

bool solve_sudoku(std::vector<std::vector<int>>& grid) {

	return solve_sudoku(grid, 0, 0);
}

bool is_possible_queen(std::vector<int>& queens, int col) {

	int row = queens.size();

	for (int i = 0; i < queens.size(); i++)
	{
		if (queens[i] == col) {
			return false;
		}
	}

	for (int i = 0; i < queens.size(); i++)
	{
		if (std::abs(queens[i] - col) == std::abs(row - i)) {
			return false;
		}

	}

	return true;

}

bool s_nqueen(std::vector<int>& queens, int n) {

	if (queens.size() == n) {
		printSequence(queens);
		return true;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			if (is_possible_queen(queens, i)) {
				queens.push_back(i);
				s_nqueen(queens, n);
				queens.pop_back();
			}
		}
		return false;
	}
}

void solve_nqueen(int n) {

	std::vector<int> queens({});

	s_nqueen(queens, n);
}