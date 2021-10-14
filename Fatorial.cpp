#include<iostream>
#include"Fatorial.h"

/*
Computa n! recursivamente
	Input: um inteiro não negativo n
	Output: O valor de n!

	if n=0
		return 1
	else
		return F(n-1) * n
*/

int fatorial(int n){

	int f = 0;

	if (n == 0) {
		f = 1;
	}

	else {
		f = fatorial(n - 1) * n;
		
	}

	//std::cout << f << std::endl;
	return f;
}


