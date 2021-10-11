#include<iostream>
#include"EuclideanAlgorithmGCD.h"

/*
Basic Euclidean Algorithm for GCD
	Calcula gcd(m,n) pelo algoritmo de Euclides(maior divisor comum)
	Input: dois inteiros não negativos e diferentes de zero (m, n)
	Output: máximo divisor comum de m e n

	m mod n : resto da divisão de m por n


	while n!=0
		r <- (m mod n)
		m <- n
		n <- r
	return m
*/


void gcd(int m, int n) {
	
	int r;

	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	std::cout << m << std::endl;
}
