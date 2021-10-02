#include <iostream> //possui m�todos cin e cout
#include <vector>
#include"Utils.h"

// Aqui s�o implementados os algoritmos complementares: os utilit�rios

// para imprimir um vetor
// nome Iterable definido para o m�todo template, pois estamos iterando sobre a sequencia
// o template aqui serve para iterar sobre sem precisar definir antecipadamento o tipo
template<class Iterable>  // m�todo void: n�o retorna valor

void printSequence (Iterable& seq) { // & significa passar por referencia o objeto
	
	//Essa se��o for pode ser generalizada para listas tamb�m
	//m�todo Auto infere o tipo
	for (auto e : seq) { //a cada itera��o a vari�vel e recebe um elemento do vetor
		std::cout << e << " ";
	}
	std::cout << std::endl;
}


template<class Iterable>
void printSequenceSequence(Iterable& seq) {
	for (auto s : seq) {
		for (auto e : s) {
			std::cout << e << " ";
		}
		std::cout << " , ";
	}
	std::cout << std::endl;
}
