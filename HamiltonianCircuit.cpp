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
bool is_possible_hamiltonian(int node, std::vector<std::vector<int>>& graph, std::vector<int>& path) { // path é o caminho 

	if (path.size() == 0){ // verifica se o path esta vazio
		return true;
	}
	else {
		for (size_t i = 0; i < path.size(); i++){

			if (node == path[i]) { // verifica se ó nó já foi inserido
				return false;
			}
		}

		if (graph[path.back()][node] == 0) { // verifica se o ultimo nó inserido no path e o  novo nó tem aresta
			return false;
		}

		if (path.size() == graph.size() - 1 && graph[node][path.front()] == 0) { // verifica se falta a ultima posição e se esse novo nó tem aresta com o primeiro
			return false;
		}
	}

	return true;
}

// resolver o path 
void solve_hamiltonian_circuit(std::vector<std::vector<int>>& graph, std::vector<int>& path) { 

	if (path.size()  == graph.size()) {	// verifica se o path esta completo
			printSequence(path);			// imprimir a solução
		}

	else {
		for (int i = 0; i < graph.size(); i++) {

			if (is_possible_hamiltonian(i, graph, path)) { // verifica se o nó pode ser inserido
			path.push_back(i);						// add a posição ao caminho
			solve_hamiltonian_circuit(graph, path); // tenta resolver
			path.pop_back();						// apaga ultima posição e tenta resolver
			}

		}
	}
}

// solve para o usuário

void hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	std::vector<int> path({0});

	solve_hamiltonian_circuit(graph, path); 
}













