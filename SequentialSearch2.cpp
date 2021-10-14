#include<vector>
#include <iostream>
#include"SequentialSearch2.h"

/*
SequentialSearch2 (A [0..n], K)

	Implementa a pesquisa sequencial com uma chave de pesquisa como um sentinela
	Input: Uma matriz A de n elementos e uma chave de pesquisa K
	Output: o índice do primeiro elemento em A [0..n - 1] cujo valor é
		   igual a K ou -1 se nenhum elemento for encontrado

	A[n] <- K
	I <- 0
	while A[i] != K do
			i <- i+1
	if i<n return i
	else return -1
*/

template<typename T>

void seq_search2(std::vector<T>& v) {

	int n = (sizeof(v) / sizeof(v[0]));
	int k = v[n] ;
	int i = 0;

	while (v[i] != k) {
		i+=1;

		if (i < n) {
			std::cout << i << std::endl;
		}

		else {
			std::cout << -1 << std::endl;
		}

	}


}

