#include"BruteForceStringMatch.h"
#include <iostream>
#include <vector>
#include <string>

/*
BruteForceStringMatch(T [0..n − 1], P[0..m − 1])

	Implementa correspondência de string de força bruta
		Input: Um array T [0..n - 1] de n caracteres representando um texto e um array P [0..m - 1] de m caracteres representando um padrão
		Output: o índice do primeiro caractere do texto que inicia uma substring correspondente ou -1 se a pesquisa não for bem-sucedida

		for i ← 0 to n − m do
			j ←0
			while j <m and P[j ]= T [i + j ] do
				j ←j + 1
			if j = m return i
		return −1
*/

void string_match(std::vector<std::string>& texto, std::vector<std::string>& padrao) {

	int n = texto.size();
	int m = padrao.size();

	int i;

	for (size_t i = 0; i < n-m; i++) {
		int j = 0;

		while (j < m && (padrao[j] == texto[i+j])) {
			j++;
		}

		if (j == m) {
			std::cout << i << std::endl;
		}

		std::cout << -1 << std::endl;
	}
}





