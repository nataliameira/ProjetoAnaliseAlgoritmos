#include <vector>

// ============= Change-Making - recursivo ========== //

int get_coins_recursive(int change, std::vector<int>& coins) {

	if (change == 0) {
		return 0;
	}
	else {

		int min_coins = std::numeric_limits<int>::max();

		for (size_t i = 0; i < coins.size(); i++)
		{
			if (change >= coins[i]) {
				int temp = get_coins_recursive(change - coins[i], coins);
				min_coins = (temp < min_coins) ? temp : min_coins;
			}

		}

		return min_coins + 1;
	}

}

// ============= Change-Making - prog dinâmica ========== //

int get_coins(int change, std::vector<int>& coins) { // change é o troco

	std::vector<int> f(change + 1); // +1 pq começamos de 0

	f[0] = 0;

	for (size_t i = 1; i < f.size(); i++) // i é o troco que queremos dar: 1, 2, 3...
	{
		int min_coins = std::numeric_limits<int>::max();
		for (size_t j = 0; j < coins.size(); j++)
		{
			if (i >= coins[j]) {
				int temp = f[i - coins[j]]; // não fazemos chamadas recursivas, apenas pegamos o valor
				min_coins = (temp < min_coins) ? temp : min_coins;
			}
		}

		f[i] = min_coins + 1; // atualizo a memoria 
	}

	return f.back();
}