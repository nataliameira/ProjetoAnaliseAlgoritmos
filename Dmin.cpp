#include<vector>
#include<iostream>
#include<concepts>
#include "Dmin.h"

/*
Encontra a dist�ncia entre os dois elementos mais pr�ximos em uma matriz de n�meros.
	Input: A[0..n-1]
	Output: a menor dist�ncia entre  dois elementos

	dmin <- {}
	for i <- 0 to n-1 do
		for j <- 0 to n-1 do
			if i!=j and |A[i] - A[j]| < dmin
			dmin <- |A[i] - A[j]|
	return dmin
*/

template <typename T>

void dist_min(std::vector<T>& v){
	
	int dmin = 999;

	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < v.size(); j++) {
			if (i != j && abs(v[i] - v[j]) < dmin) {
				dmin = abs(v[i] - v[j]);
			}
		}
	}
	std::cout << "A menor distancia entre dois elementos eh: " << dmin << std::endl;
}







