#include <vector>
#include <algorithm>
#include "Knapsack.h"


int mf_knapsack(int i, int j, std::vector<std::vector<int>>& F,
	std::vector<int>& values, std::vector<int>& weights) {


	if (F[i][j] < 0) {
		int value = -1;
		if (j < weights[i - 1]) {
			value = mf_knapsack(i - 1, j, F, values, weights);
		}
		else {
			value = std::max(mf_knapsack(i - 1, j, F, values, weights),
				values[i - 1] + mf_knapsack(i - 1, j - weights[i - 1], F, values, weights));
		}
		F[i][j] = value;
	}

	return F[i][j];

}

int mf_knapsack(std::vector<int>& values, std::vector<int>& weights, int capacity) {

	std::vector<std::vector<int>> F(weights.size() + 1, std::vector<int>(capacity + 1, -1));

	for (size_t i = 0; i < F.size(); i++)
	{
		F[i][0] = 0;
	}

	for (size_t i = 0; i < F[0].size(); i++)
	{
		F[0][i] = 0;
	}

	return mf_knapsack(F.size() - 1, F[0].size() - 1, F, values, weights);

}