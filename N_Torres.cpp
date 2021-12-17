#include<vector>
#include<iostream>
#include<concepts>
#include<algorithm>
#include<math.h>
#include<functional>
#include "Utils.h"

//=============== Simulado ============//
 
bool is_possible_torres(std::vector<int>& torres, int i) {


	if (torres.size() == 0) {
		return true;
	}

	else {
		for (int j = 0; j < torres.size(); j++) {
			if (torres[j] == i) {
				return false;
			}
		}
	}

	return true;
}


bool solve_ntorres(int& n, std::vector<int>& torres) {

	if (torres.size() == n) {
		printSequence(torres);
		return true;
	}

	else {
		for (int i = 0; i < n; i++) {

			if (is_possible_torres(torres, i)) {
				torres.push_back(i);
				solve_ntorres(n, torres);
				torres.pop_back();
			}
		}
		return false;
	}
}

void ntorres(int& n) {

	std::vector<int> torres({});

	solve_ntorres(n, torres);
}





