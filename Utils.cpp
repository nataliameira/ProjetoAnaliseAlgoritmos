#include <iostream> //possui métodos cin e cout
#include <vector>
#include"Utils.h"

// Aqui são implementados os algoritmos complementares: os utilitários

// para imprimir um vetor
// nome Iterable definido para o método template, pois estamos iterando sobre a sequencia
// o template aqui serve para iterar sobre sem precisar definir antecipadamento o tipo
template<class Iterable>  // método void: não retorna valor

void printSequence (Iterable& seq) { // & significa passar por referencia o objeto
	
	//Essa seção for pode ser generalizada para listas também
	//método Auto infere o tipo
	for (auto e : seq) { //a cada iteração a variável e recebe um elemento do vetor
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
