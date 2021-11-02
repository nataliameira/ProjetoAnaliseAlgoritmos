/*
	Encontrar o maior e menor valor em um vetor por:
		- busca exaustiva
		- dividir para conquistar
*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>


template<typename T>

void minmax_buscaexaustiva(std::vector<T>& v) {

	double min = INFINITY;
	int max = 0;

	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] <= min) {
			min = v[i];
		}

		else
			if (v[i] >= max) {
				max = v[i];
			}
	}

	std::cout << min << std::endl << max << std::endl << std::endl;
}




int minmax_divconq(std::vector<int>& v) {

	std::vector<int> t;
	std::vector<int> u;

	int n = v.size();

	int min_t;
	int min_v;

	if (v.size() == 1) {
		return v[0];
	}


	if (n > 1) {

		int i;

		for (i = 0; i < v.size() / 2; i++) {
			t.push_back(v[i]);
		}

		for (; i < v.size(); i++) {
			u.push_back(v[i]);
		}

	}

	min_t = minmax_divconq(t);
	min_v = minmax_divconq(u);

	if (min_t < min_v) {
		return min_t;
	}
	else {
		return min_v;
	}
}