#include <list>
#include <vector>
#include <limits>
#include <cfloat>
#include "SpanningTree.h"

std::vector<std::vector<float>> prim(std::vector<std::vector<float>> graph) {
	/* Computes a minimum spanning tree using Prim's algorithm
	*/

	std::vector<std::vector<float>> tree(graph.size(), std::vector<float>(graph.size(), 0.0));
	std::list<int> tree_nodes({ 0 });
	std::list<int> nodes({});

	for (int i = 1; i < graph.size(); i++)
	{
		nodes.push_back(i);
	}

	for (size_t t = 0; t < tree.size() - 1; t++)
	{

		float min_w = FLT_MAX;
		int min_i = -1;
		int min_j = -1;

		// For each vertex in the tree
		for (auto vt : tree_nodes)
		{
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


std::vector<std::vector<float>> prim2(std::vector<std::vector<float>> graph) {
	/* Computes a minimum spanning tree using Prim's algorithm
	*/

	std::vector<std::vector<float>> tree(graph.size(), std::vector<float>(graph.size(), 0.0));
	std::vector<bool> tree_nodes(graph.size(), false);
	std::vector<float> vals(graph.size(), FLT_MAX);
	std::vector<int> parents(graph.size(), -1);

	vals[0] = 0;


	for (int t = 0; t < tree.size() - 1; t++)
	{

		int u = min_node(vals, tree_nodes);
		tree_nodes[u] = true;

		// For each vertex in the tree
		for (int v = 0; v < graph.size(); v++)
		{
			if (graph[u][v] != 0 && tree_nodes[v] == false && graph[u][v] < vals[v]) {
				parents[v] = u;
				vals[v] = graph[u][v];
			}
		}

	}

	for (size_t i = 1; i < parents.size(); i++)
	{
		tree[parents[i]][i] = graph[parents[i]][i];
	}

	return tree;

}