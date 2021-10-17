#include<iostream>
#include<concepts>
#include<vector>
#include<algorithm>
#include"MergeSort.h"

/*
Mergesort (A [0..n - 1])

	Classifica a matriz A [0..n - 1] por mesclagem recursiva	
		Input: um array A [0..n - 1] de elementos solicitáveis
		Output: Array A [0..n - 1] classificado em ordem não decrescente

		if n > 1
			copy A[0..[n/2] − 1] to B[0..[n/2] − 1]
			copy A[[n/2]..n − 1] to C[0..[n/2] − 1]
			Mergesort(B[0..[n/2] − 1])
			Mergesort(C[0..[n/2] − 1])
			Merge(B, C, A) //see below

Merge(B[0..p − 1], C[0..q − 1], A[0..p + q − 1])
	
	Mescla duas arrays classificadas em uma array classificada
		Input: arrays B [0..p - 1] e C [0..q - 1], ambas classificadas
		Output: array classificada A [0..p + q - 1] dos elementos de B e C


	i <- 0; j <- 0; k<- 0
	while i < p and j < q do
		if B[i]≤ C[j ]
			A[k] <- B[i]; i ←i + 1
		else A[k] <- C[j ]; j ←j + 1
		k <- k + 1
	if i = p
		copy C[j..q − 1] to A[k..p + q − 1]
	else copy B[i..p − 1] to A[k..p + q − 1]

*/



void merge(std::vector<int> B, std::vector<int> C, std::vector<int>& A) {

	int i = 0, j = 0, k = 0;
	int p = B.size();
	int q = C.size();

	while (i < p && j < q) {

		if (B[i] <= C[j]) {
			A[k] = B[i];
			i += 1;
		}

		else {
			A[k] = C[j];
			j += 1;
		}

		k++;
	}

	if (i == p) {
		A.push_back(C[j]);
	}

	else {
		A.push_back(B[i]);
	}
}


void merge_sort(std::vector<int>& A) {

	std::vector<int> B;
	std::vector<int> C;

	int n = A.size();

	if (n > 1) {
		for (size_t i = 0; i < ((A.size()/2) - 1) ; i++) {
			B.push_back(A[i]);
			break;
		}
		
		for (size_t i = A.size()/2 ; i < A.size(); i++) {
			C.push_back(A[i]);
			break;
		}

		merge_sort(B);
		merge_sort(C);

		merge(B, C, A);
	}
}