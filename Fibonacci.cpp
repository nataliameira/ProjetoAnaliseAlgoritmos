#include"Fibonacci.h"

/*
Calcula o enésimo número de Fibonacci recursivamente usando sua definição
	Input: um inteiro não-negativo n
	Output: o enésimo número de Fibonacci

	if n <= 1
		return n
	else
		return F(n − 1) + F(n − 2)
*/

int fibonacci(int n) {

	int f;

	if (n <= 1) {
		f = n;
	}

	else {
		f = fibonacci(n - 1) + fibonacci(n - 2);
	}

	return f;
}

