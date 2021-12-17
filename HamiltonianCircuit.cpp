#include<vector>
#include<iostream>
#include<concepts>
#include<math.h>
#include "Utils.h"

/*
	Hamiltonian Circuit Problem

	Gera todos os caminhos poss�veis sem repetir nenhum n� em um grafo.

	Input: Um grafo G que pode ser representado em uma matriz de adjacencias onde G[v][v] s�o os v�rtices 
			do grafo. Um grafo de valor [i] [j] � 1 se houver um v�rtice direto de i para j, 
			caso contr�rio, grafo [i] [j] � 0.
	Output: Um vector path contendo o caminho (Hamiltonian Circuit). O caminho [i] deve representar o i�
			v�rtice no Hamiltonian Circuit. O c�digo tamb�m deve retornar falso se n�o houver um Hamiltonian Circuit 
			no grafo.

	Restri��es:
		- Testar todos os v�rtices;
		- Verificar se um v�rtice i j� est� no grafo;
		- Verificar se existe uma aresta entre os v�rtices;
		- Fixar o n� inicial para n�o obter caminhos duplicados.
*/


// verificar se � poss�vel add um v�rtice
bool is_possible_hamiltonian(int node, std::vector<std::vector<int>>& graph, std::vector<int>& path) { // path � o caminho 

	if (path.size() == 0){ // verifica se o path esta vazio
		return true;
	}
	else {
		for (size_t i = 0; i < path.size(); i++){

			if (node == path[i]) { // verifica se � n� j� foi inserido
				return false;
			}
		}

		if (graph[path.back()][node] == 0) { // verifica se o ultimo n� inserido no path e o  novo n� tem aresta
			return false;
		}

		if (path.size() == graph.size() - 1 && graph[node][path.front()] == 0) { // verifica se falta a ultima posi��o e se esse novo n� tem aresta com o primeiro
			return false;
		}
	}

	return true;
}

// resolver o path 
void solve_hamiltonian_circuit(std::vector<std::vector<int>>& graph, std::vector<int>& path) { 

	if (path.size()  == graph.size()) {	// verifica se o path esta completo
			printSequence(path);			// imprimir a solu��o
		}

	else {
		for (int i = 0; i < graph.size(); i++) {

			if (is_possible_hamiltonian(i, graph, path)) { // verifica se o n� pode ser inserido
			path.push_back(i);						// add a posi��o ao caminho
			solve_hamiltonian_circuit(graph, path); // tenta resolver
			path.pop_back();						// apaga ultima posi��o e tenta resolver
			}

		}
	}
}

// solve para o usu�rio

void hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	std::vector<int> path({0});

	solve_hamiltonian_circuit(graph, path); 
}













