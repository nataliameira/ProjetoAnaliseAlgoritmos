#include <vector>
#include <iostream>
#include <limits>
#include "Utils.h"
#include "BranchAndBound.h"


int cost(std::vector<std::vector<int>>& graph, std::vector<int>& tour) {

	int cost = 0;

	for (int i = 0; i < tour.size(); i++)
	{
		cost += graph[tour[i]][tour[(i + 1) % tour.size()]];
	}

	return cost;

}

int heuristic(std::vector<int>& tour, int min_edge, int n) {

	return (n - tour.size() + 1) * min_edge;

}

// método que testa
bool is_possible_tsp(std::vector<int>& tour, int city) {

	for (size_t i = 0; i < tour.size(); i++)
	{
		if (tour[i] == city) {
			return false;
		}
	}

	return true;
}

// método que armazena
void solve_tsp(std::vector<int>& tour, std::vector<std::vector<int>>& graph, int min_edge, int bound,
	std::vector<int>& best_tour, int best_cost) {

	if (tour.size() == graph.size()) { //graph.size fornece o número de cidades
		int tour_cost = cost(graph, tour);
		if (tour_cost < bound) {
			bound = tour_cost;
			if (tour_cost < best_cost) {
				best_cost = tour_cost;
				best_tour = tour;
			}
		}
		printSequence(tour);
		std::cout << "cost: " << tour_cost << std::endl;
		std::cout << "==================== " << std::endl;
		return;
	}
	else {
		for (int i = 1; i < graph.size(); i++)
		{
			if (is_possible_tsp(tour, i)) {
				if ((cost(graph, tour) + heuristic(tour, min_edge, i)) < bound) {
					tour.push_back(i);
					solve_tsp(tour, graph, min_edge, bound, best_tour, best_cost);
					tour.pop_back();
				}
			}
		}
		return;
	}

}

void solve_tsp(std::vector<std::vector<int>>& graph) {

	int minedge = std::numeric_limits<int>::max();

	for (size_t i = 0; i < graph.size(); i++)
	{
		for (size_t j = 0; j < graph.size(); j++)
		{
			minedge = (graph[i][j] < minedge) ? graph[i][j] : minedge;
		}
	}

	std::vector<int> tour({ 0 });
	std::vector<int> best_tour({ 0 });
	static int best_cost = std::numeric_limits<int>::max();


	solve_tsp(tour, graph, minedge, 17, best_tour, best_cost);

	std::cout << "BEST Tour: " << std::endl;
	printSequence(best_tour);
	std::cout << "cost: " << cost(graph, best_tour) << std::endl;
	std::cout << "==================== " << std::endl;
}