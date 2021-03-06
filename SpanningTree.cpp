#include <list>
#include <vector>
#include <limits>
#include <cfloat>
#include "SpanningTree.h"

/*
Algoritmo de Prim para a constru??o de uma minimums spanning tree
	
	Input: um grafo conectado G={V,E}
	Output: Et, o conjunto de arestas que comp?em uma minimum spanning tree
*/


/* ========= Algoritmo de Prim: Minimum Spanning Tree =========*/
//O(n^3)

std::vector<std::vector<float>> prim(std::vector<std::vector<float>> graph) {
	
	std::vector<std::vector<float>> tree(graph.size(), std::vector<float>(graph.size(), 0.0));
	std::list<int> tree_nodes({ 0 });
	std::list<int> nodes({});

	for (int i = 1; i < graph.size(); i++)	{
		nodes.push_back(i);
	}
	// enquanto a arvore nao contiver todos os n?s
			// para cada n?, u, da arvore, encontrar a aresta de menor custo a=(u,v)
			 // de forma que u esta na arvore e v nao esta na arvore.
	for (size_t t = 0; t < tree.size() - 1; t++) { // quem vai add na arvore (n? de menor custo)
	
		float min_w = FLT_MAX;
		int min_i = -1;
		int min_j = -1;

		// For each vertex in the tree
		for (auto vt : tree_nodes){
			// find the edge with minimum cost
			for (auto v : nodes) {
				if (v != vt && graph[vt][v] <= min_w && graph[vt][v] != 0) {
					min_w = graph[vt][v];
					min_i = vt;
					min_j = v;
				}
			}
		}

		tree_nodes.push_back(min_j);
		nodes.remove(min_j);
		tree[min_i][min_j] = graph[min_i][min_j];
		graph[min_i][min_i] = FLT_MAX;
	}
	return tree;
}

int min_node(std::vector<float>& vals, std::vector<bool>& nodes) {
	float min = FLT_MAX;
	int min_idx = 0;

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == false && vals[i] < min) {
			min = vals[i];
			min_idx = i;
		}
	}

	return  min_idx;
}

/* ========= Algoritmo de Prim: Minimum Spanning Tree =========*/
// O(n^2)    n = vertices

std::vector<std::vector<float>> prim2(std::vector<std::vector<float>> graph) {
	/* Computes a minimum spanning tree using Prim's algorithm*/

	std::vector<std::vector<float>> tree(graph.size(), std::vector<float>(graph.size(), 0.0));
	std::vector<bool> tree_nodes(graph.size(), false);
	std::vector<float> vals(graph.size(), FLT_MAX);
	std::vector<int> parents(graph.size(), -1);

	vals[0] = 0; //define fila de prioridade


	for (int t = 0; t < tree.size() - 1; t++){

		int u = min_node(vals, tree_nodes);
		tree_nodes[u] = true;

		// For each vertex in the tree
		for (int v = 0; v < graph.size(); v++){

			if (graph[u][v] != 0 && tree_nodes[v] == false && graph[u][v] < vals[v]) {
				parents[v] = u;
				vals[v] = graph[u][v];
			}
		}
	}

	for (size_t i = 1; i < parents.size(); i++){

		tree[parents[i]][i] = graph[parents[i]][i];
	}

	return tree;
}


/* ========= Algoritmo de Prim: Minimum Spanning Tree =========*/
// O(n log n)    n = arestas
// estrutura heap p/ organizar fila de prioridade

std::vector<Edge> primElogE(std::vector<std::vector<Node>> graph) {

	std::vector<bool> included(graph.size(), false); // lista para saber quais n?s est?o na ?rvore, iniciada como false, pois ainda n?o tem nenhum n? add
	std::priority_queue<Edge, std::vector<Edge>, GreaterEdge> edges({}); // fila de prioridade: tipo, estrutura de dados, 
																			//crit?rio de prioridade (GreaterEdge - maior prioridade os elementos de menor valor
	std::vector<Edge> tree; // conforme tira da fila de prioridade, add nessa arvore, que ser? retornada no final

	edges.push(Edge(-1, 0, 0)); // pega da raiz (-1, nao existe), para o n? zero com custo zero.

	while (!edges.empty()) { // enquanto a fila n?o estiver vazia

		Edge selected = edges.top(); // copia o primeiro elemento da fila de prioridade, menor valor
		edges.pop();				// retira do  heap

		if (!included[selected.to]) { //se ainda n?o tiver sido inserido
			tree.push_back(selected);	// add ? elemento priorit?rio na ?rvore
			included[selected.to] = true; // marca como inserido

			for (Node n : graph[selected.to]) {  // para cada n? n conectado ao n? "to" selecionado
				if (!included[n.id]) {			// se ele ainda nao tiver no grafo
					edges.push(Edge(selected.to, n.id, n.val)); //log E - adicionamos na fila de prioridade
				}					// selected.to = log n na base 2 (n ? qtos elementos tem no heap, numero de arestas)
			}
		}

	}

	// E log E
	return tree;
}
