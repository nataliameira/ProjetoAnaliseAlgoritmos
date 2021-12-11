#include<vector>
#include<iostream>
#include<concepts>
#include<math.h>
#include "Utils.h"
#include"SubsetSum.h"

/*
	Subset-Sum Problem
	Encontra os subconjuntos de um determinado conjunto A = {a1,. . . , an} de n inteiros positivos
		cuja soma é igual a um determinado inteiro positivo d.

	Input: um array A = {a1,. . . , an} de n inteiros positivos e um inteiro positivo d.
	Output: um subconjunto cuja soma dos elementos seja igual a d.

*/

// verificar se a adição de um nó chega na solução

bool node_sum(std::vector<int>& set, std::vector<int>& subset, int& d, int& i, int& right_node, int& left_node) { //fç que guarda os nós com a soma
		
	if (right_node > d || left_node > d) {	// verifica se o valor do nó é maior que a soma
		return false;
	}

	return true;
}

bool subset_sum(std::vector<int>& set, std::vector<int>& subset, int& d, int& right_node, int& left_node) {

	if (right_node == d || left_node == d){
		printSequence(subset);
		return true;
	}

	else {
		for (int i = 0; i < set.size(); i++) {

			if (node_sum(set, subset, d, i, right_node, left_node)) {
				right_node = left_node;
				left_node += set[i];

				subset.push_back(set[i]);
				subset_sum(set, subset, d, right_node, left_node);
				subset.pop_back();
				left_node = left_node - set[i];
			}
		}

		return false;
	}
}

bool subset(std::vector<int>& set, int& d) {

	std::vector<int> subset({});

	int right_node = 0;
	int left_node = 0;

	return subset_sum(set, subset, d, right_node, left_node);
}






