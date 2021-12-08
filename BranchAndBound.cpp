#include <vector>
#include <iostream>
#include <limits>
#include "Utils.h"
#include "BranchAndBound.h"

// =========== Caixeiro Viajante ============//  

int cost(std::vector<std::vector<int>>& graph, std::vector<int>& tour) {

	int cost = 0;

	for (size_t i = 0; i < tour.size() - 1; i++){

		cost += graph[tour[i]][tour[i + 1]];	//add aresta
	}

	if (tour.size() == graph.size()) {		// verifica se tour está completo
		cost += graph[tour[graph.size() - 1]][tour[0]];  //add custo de voltar p cidade inicial
	}

	return cost;
}

int heuristic(std::vector<int>& tour, int min_edge, int n_cities) { // verificar qtas cidades faltam, multiplicar pelo custo da menor aresta, obter estimativa

	return (n_cities - tour.size() + 1) * min_edge;

}

// método que testa
bool is_possible_tsp(std::vector<int>& tour, int city) { 

	for (size_t i = 0; i < tour.size(); i++){

		if (tour[i] == city) {
			return false;
		}
	}

	return true;
}

// método que armazena
void solve_tsp(std::vector<int>& tour, std::vector<std::vector<int>>& graph, int min_edge, int& bound,
	std::vector<int>& best_tour, int best_cost) {
			// min_edge = menor aresta que calcula a heuristica
			// bound = limite para descidir se expande um caminho
			//best_tour = armazena melhor rota
			// best_cost = armazena melhor custo

	if (tour.size() == graph.size()) { //graph.size fornece o número de cidades
		int tour_cost = cost(graph, tour);

		if (tour_cost < bound) {
			bound = tour_cost;
		}

		if (tour_cost < best_cost) {
			best_tour = tour;
			best_cost = tour_cost;
		}

		printSequence(tour);
		std::cout << "cost: " << tour_cost << std::endl;
		std::cout << "==================== " << std::endl;
		
		return;
	}
	else {
		for (int i = 1; i < graph.size(); i++){		// inserir a cidade i

			if (is_possible_tsp(tour, i)) {		//verifica

				if ((cost(graph, tour) + heuristic(tour, min_edge, i)) < bound) {
					tour.push_back(i);												// add cidade
					solve_tsp(tour, graph, min_edge, bound, best_tour, best_cost); // faz chamada recursiva p  completar
					tour.pop_back(); //qdo retorna, tira e tenta outra possibilidade
				}
			}
		}
		return;
	}
}

void solve_tsp(std::vector<std::vector<int>>& graph) { // método que o usuário passa o grafo

	int minedge = std::numeric_limits<int>::max();

	for (size_t i = 0; i < graph.size(); i++){

		for (size_t j = 0; j < graph.size(); j++){

			minedge = (graph[i][j] < minedge) ? graph[i][j] : minedge;
		}
	}

	std::vector<int> tour({ 0 });
	std::vector<int> best_tour({ 0 });
	int best_cost = std::numeric_limits<int>::max();
	int bound = 15; // std::numeric_limits<int>::max();


	solve_tsp(tour, graph, minedge, bound, best_tour, best_cost);

	std::cout << "BEST Tour: " << std::endl;
	printSequence(best_tour);
	std::cout << "cost: " << cost(graph, best_tour) << std::endl;
	std::cout << "==================== " << std::endl;
}