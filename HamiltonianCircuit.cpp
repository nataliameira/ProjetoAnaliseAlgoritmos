#include<vector>
#include<iostream>
#include<concepts>
#include<math.h>
#include "Utils.h"

/*
	Hamiltonian Circuit Problem

	Gera todos os caminhos possíveis sem repetir nenhum nó em um grafo.

	Input: Um grafo G que pode ser representado em uma matriz de adjacencias onde G[v][v] são os vértices 
			do grafo. Um grafo de valor [i] [j] é 1 se houver um vértice direto de i para j, 
			caso contrário, grafo [i] [j] é 0.
	Output: Um vector path contendo o caminho (Hamiltonian Circuit). O caminho [i] deve representar o iº
			vértice no Hamiltonian Circuit. O código também deve retornar falso se não houver um Hamiltonian Circuit 
			no grafo.

	Restrições:
		- Testar todos os vértices;
		- Verificar se um vértice i já está no grafo;
		- Verificar se existe uma aresta entre os vértices;
		- Fixar o nó inicial para não obter caminhos duplicados.
*/

// verificar se é possível add um vértice
bool is_possible_hamiltonian(std::vector<std::vector<int>>& graph, std::vector<int>& path, int& i, int& j) { // path é o caminho 
	
	if (graph[i][j] == 0) { // verifica se o elemento naquela posição é zero, então não existe aresta
		return false;
	}

	for (int k = 0; k < path.size(); k++) {

		if (j == path[k]) { // a posição (nó) não pode se repetir
			return false;
		}
	}

	return true;
}

// resolver o path 
bool solve_hamiltonian_circuit(std::vector<std::vector<int>>& graph, std::vector<int>& path) { 

	if (path.size() == graph.size() ) {			
		printSequence(path);			// imprimir a solução
		return true;
	}

	else {
			for (int i = 0; i < graph.size(); i++) {
				for (int j = 0; j < graph.size(); j++) {

					if (is_possible_hamiltonian(graph, path, i, j)) { // verifica se é uma posição que contem aresta
								path.push_back(j);						// add a posição ao caminho
								solve_hamiltonian_circuit(graph, path); // tenta resolver
								path.pop_back();						// apaga ultima posição e tenta resolver
					}
				}
			}

			return false;
	}
}

// solve para o usuário

bool hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	int n = 0;

	std::vector<int> path({n}); // o caminho é um vetor do tamanho no nº de nós do grafo, mas começa apenas com o elemento 0 na posição (0)

	return solve_hamiltonian_circuit(graph, path); 

}













