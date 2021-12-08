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
bool is_possible_hamiltonian(std::vector<std::vector<int>>& graph, std::vector<int>& path) { // path é o caminho 

	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {

			for (int k = 0; k < path.size(); k++) {

				if (i == k || j == k) { // a posição (nó) não pode se repetir
					return false;
				}

				if (graph[i][j] == 0) { // qdo for zero, não tem aresta
					return false;
				}
			}
		}
	}

	return true;
}


// resolver o path 
bool solve_hamiltonian_circuit(std::vector<std::vector<int>>& graph, std::vector<int>& path) { 

	if (path.back() != -1 ) {			// qdo o ultimo elemento for diferente de -1, preencheu todo o path
		printSequence(path);			// imprimir a solução
		return true;
	}

	else {
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph.size(); j++) {

				if (is_possible_hamiltonian(graph, path)) { // verifica se é uma posição que contem aresta
					path.push_back(i);						// add a posição ao caminho
					solve_hamiltonian_circuit(graph, path); // tenta resolver
					path.pop_back();						// apaga ultima posição e tenta resolver
				}
			}
		}
		return false;
	}

}

// solve para o úsuário

bool hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	std::vector<int> path(graph.size(), -1); // o caminho é um vetor do tamanho no nº de nós do grafo, preenchido com -1

	return solve_hamiltonian_circuit(graph, path); 

}













