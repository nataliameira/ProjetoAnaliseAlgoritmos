#include <vector>
#include <algorithm>
#include "CoinRow.h"

/*CoinRow
	Aplica a fórmula: F(n) = max(Cn + F(n-2), F(n-1)) para encontrar a
		quantidade máxima de dinheiro que pode ser retirado de uma fila 
		de moedas, sem escolher duas moedas adjacentes.
	Input: array C[1..n] de inteiros positivos indicando os valores das moedas.
	Output: a quantidade máxima de dinheiro que pode ser retirada.

	F[0] <- 0
	F[1] <- 1
	for i <- 2 to n do
		F[i] <- max(C[i] + F[i-2], F[i-1]
	return F[n]
*/


float coin_row_dynamic(const std::vector<float>& coins) {

	std::vector<float> f(coins.size(), 0);
	f[1] = coins[1];

	for (size_t i = 2; i < f.size(); i++)
	{
		f[i] = std::max(coins[i] + f[i - 2], f[i - 1]);
	}


	return f.back();
}


float coin_row_recursive(const std::vector<float>& coins, int i) {

	if (i == 0) {
		return 0;
	}
	else if (i == 1) {
		return coins[1];
	}
	else {
		return std::max(coins[i] + coin_row_recursive(coins, i - 2),
			coin_row_recursive(coins, i - 1));
	}
}

float coin_row_recursive(const std::vector<float>& coins) {
	return coin_row_recursive(coins, coins.size() - 1);
}