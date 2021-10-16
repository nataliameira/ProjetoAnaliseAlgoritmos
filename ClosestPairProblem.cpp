#include"ClosestPairProblem.h"
#include<vector>
#include <iostream>
#include <algorithm>
#include <cmath> 

/*
Brute Force Closest Pair Problema

Encontra  a distância entre dois pontos mais próximos no plano por força bruta
		Input: uma lista P de n(n >=2) pontos p1(x1,y1), ..., pn(xn, yn)
		Output: a distância entre o par de pontos mais próximo

		d <- infinito
		for  i <- 1 to n-1 do
			for j <- i+1 to n do
				d <- min(d, sqrt((xi-xj)^2 + (yi-yj)^2 )		// sqrt é a raiz quadrada
		return d
*/


void closest_pair(std::vector<int>& x, std::vector<int>& y) {

	double d = INFINITY;
	double m;

	for (size_t i = 0; i < x.size(); i++) {
		for (size_t j = i + 1; j < x.size(); j++) {
			m = std::sqrt(std::pow((x[i] - x[j]), 2) + std::pow((y[i] - y[j]), 2));
			d = std::min(d, m);
		}
	}
	
	std::cout << d << std::endl;
}
