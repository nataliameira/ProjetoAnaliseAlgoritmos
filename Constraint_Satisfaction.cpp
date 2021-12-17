#include<vector>
#include<iostream>
#include<concepts>
#include<math.h>
#include "Utils.h"

/*
	P2 - PCC104
*/

bool is_possible_var(std::vector<std::vector<int>>&dom, std::vector<int>& var, int element) {

	if (var.size() == 0) {
		return true;
	}

	else {
		if (var.size() == 1 && element != var[0]) {
			return false;
		}

		else {
			if (var.size() == 3 && element < var[0]) {
				return false;
			}
			else {
				if (var.size() == 3 && element != var[2]){
					return false;
				}
			}
		}
	}

	return true;
}

bool solve_variavel(std::vector<std::vector<int>>& dom, std::vector<int>& var) {

	if (var.size() == dom.size()) {
		printSequence(var);
		return true;
	}

	else {

		for (int i = 0; i < dom[var.size()].size(); i++) {

			if (is_possible_var(dom, var, dom[var.size()][i])){
				var.push_back(dom[var.size()][i]);
				solve_variavel(dom, var);
				var.pop_back();
			}
		}
		return false;
	}
}

void variavel(std::vector<std::vector<int>>& dom) {

	std::vector<int> var({});

	solve_variavel(dom, var);
}













