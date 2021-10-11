#include<vector>
#include<iostream>
#include"CommonElements.h"

/*
Common Elements (baseado no ex.5 da p.8)

	Encontra todos os elementos comuns em duas listas
	Input: 2 listas: A[0..n-1], B[0..m-1]
	Output: elementos em comum

	for i <- 0 to n-1
		for j <- 0 to m-1 do
			if A[i] == B[j]:
			return A[i]
*/


void common_elements(std::vector<int> A, std::vector<int> B) {
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = 0; j < B.size(); j++){
			if (A[i] == B[j]) {
				std::cout << A[i] << ",";
				break;
			}
		}
	}
}


//================ Outra forma ==============//

/* 
void common_elements(std::vector<int> A, std::vector<int> B) {
	for (auto  e1: A) {
		for (auto e2: B) {
			if (e1 == e2) {
				std::cout << e1 << ",";
				break;
			}
		}
	}
}
*/