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
bool is_possible_hamiltonian(std::vector<std::vector<int>>& graph, std::vector<int>& path) { // path � o caminho 

	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {

			for (int k = 0; k < path.size(); k++) {

				if (i == k || j == k) { // a posi��o (n�) n�o pode se repetir
					return false;
				}

				if (graph[i][j] == 0) { // qdo for zero, n�o tem aresta
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
		printSequence(path);			// imprimir a solu��o
		return true;
	}

	else {
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph.size(); j++) {

				if (is_possible_hamiltonian(graph, path)) { // verifica se � uma posi��o que contem aresta
					path.push_back(i);						// add a posi��o ao caminho
					solve_hamiltonian_circuit(graph, path); // tenta resolver
					path.pop_back();						// apaga ultima posi��o e tenta resolver
				}
			}
		}
		return false;
	}

}

// solve para o �su�rio

bool hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	std::vector<int> path(graph.size(), -1); // o caminho � um vetor do tamanho no n� de n�s do grafo, preenchido com -1

	return solve_hamiltonian_circuit(graph, path); 

}













