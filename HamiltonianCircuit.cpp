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
bool is_possible_hamiltonian(std::vector<std::vector<int>>& graph, std::vector<int>& path, int& i, int& j) { // path � o caminho 
	
	if (graph[i][j] == 0) { // verifica se o elemento naquela posi��o � zero, ent�o n�o existe aresta
		return false;
	}

	for (int k = 0; k < path.size(); k++) {

		if (j == path[k]) { // a posi��o (n�) n�o pode se repetir
			return false;
		}
	}

	return true;
}

// resolver o path 
bool solve_hamiltonian_circuit(std::vector<std::vector<int>>& graph, std::vector<int>& path) { 

	if (path.size() == graph.size() ) {			
		printSequence(path);			// imprimir a solu��o
		return true;
	}

	else {
			for (int i = 0; i < graph.size(); i++) {
				for (int j = 0; j < graph.size(); j++) {

					if (is_possible_hamiltonian(graph, path, i, j)) { // verifica se � uma posi��o que contem aresta
								path.push_back(j);						// add a posi��o ao caminho
								solve_hamiltonian_circuit(graph, path); // tenta resolver
								path.pop_back();						// apaga ultima posi��o e tenta resolver
					}
				}
			}

			return false;
	}
}

// solve para o usu�rio

bool hamiltonian_circuit(std::vector<std::vector<int>>& graph) {

	int n = 0;

	std::vector<int> path({n}); // o caminho � um vetor do tamanho no n� de n�s do grafo, mas come�a apenas com o elemento 0 na posi��o (0)

	return solve_hamiltonian_circuit(graph, path); 

}













