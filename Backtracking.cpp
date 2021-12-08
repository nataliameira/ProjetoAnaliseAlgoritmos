#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "Utils.h"
#include "Backtracking.h"


// ==================== SUDOKU=============== //

// m�todo que verifica se uma determinada jogada � poss�vel
// x � linha, y � coluna
bool is_possible_sudoku(std::vector<std::vector<int>>& grid, int x, int y, int n) {

	for (int j = 0; j < grid.size(); j++){

		if (grid[x][j] == n) {	// fixa linha e varre as colunas p saber se ja tem esse valor l�
			return false;
		}
	}

	for (int i = 0; i < grid.size(); i++){

		if (grid[i][y] == n) {		//fixa coluna e varre linhas
			return false;
		}
	}

	int x0 = (x / 3) * 3;
	int y0 = (y / 3) * 3;

	for (int i = 0; i < 3; i++)	{

		for (int j = 0; j < 3; j++)	{

			if (grid[x0 + i][y0 + j] == n) { // verifica se no quadrado tem n�mero igual ao que estamos tentando inserir
				return false;
			}
		}
	}

	return true;
}

bool solve_sudoku(std::vector<std::vector<int>>& grid, int x, int y) {

	// verificar se solu��o est� completa 
	if (x == grid.size() - 1 && y == grid.size() - 1) {
		printSequenceSequence(grid);
		//std::this_thread::sleep_for(std::chrono::milliseconds(x));
		return true;
	}
	else {
		for (int i = 0; i < 9; i++)	{

			for (int j = 0; j < 9; j++)	{

				if (grid[i][j] == 0) { //verifica se a posi��o est� livre

					for (int k = 1; k <= 9; k++){ //valores poss�veis

						if (is_possible_sudoku(grid, i, j, k)) {
							grid[i][j] = k;
							//system("cls");
							//printSequenceSequence(grid);
							//std::this_thread::sleep_for(std::chrono::milliseconds(x));
							solve_sudoku(grid, i, j); // tenta preencher as outras posi��es
							grid[i][j] = 0; // desfaz para tentar outra solu��o poss�vel
						}
					}
					return false;
				}
			}
		}
	}
}

bool solve_sudoku(std::vector<std::vector<int>>& grid) {

	return solve_sudoku(grid, 0, 0); // usuario passa a grade e come�o preenchendo da posi��o 0,0
}



// ==================== N - QUEENS =============== //

bool is_possible_queen(std::vector<int>& queens, int col) { // f� auxiliar que verifica se podemos 
													//	add a rainha em uma determinada posi��o
	int row = queens.size();

	for (int i = 0; i < queens.size(); i++){
		if (queens[i] == col) {						// verifica se j� tem rainha na coluna que queremos add
			return false;
		}
	}

	for (int i = 0; i < queens.size(); i++){
													// verifica se h� ataque na diagonal
		if (std::abs(queens[i] - col) == std::abs(row - i)) { // msm distancia da linha e coluna
			return false;
		}
	}

	return true;
}

bool s_nqueen(std::vector<int>& queens, int n) { 

	if (queens.size() == n) {			// qdo a solu��o chega em n rainhas, quer dzr q concluiu
		printSequence(queens);			// imprimir a solu��o
		return true;
	}

	else {
		for (int i = 0; i < n; i++)	{ // colunas q podemos atribuir a solu�

			if (is_possible_queen(queens, i)) { // testar as solu��es 
				queens.push_back(i);
				s_nqueen(queens, n);			// resolver recursivamente p/ o restante
				queens.pop_back();				// qdo � resolver, volta uma posi��o
			}
		}
		return false;							// n�o conseguiu solu�
	}
}

void solve_nqueen(int n) { // tamanho do tabuleiro e de rainhas

	std::vector<int> queens({});

	s_nqueen(queens, n);
}