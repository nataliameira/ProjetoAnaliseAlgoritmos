#pragma once

class Node {		//permite criar estrutura com tipos diferentes, pois vector nao permite
public:
	int id; //armazenar nome do nó
	float val; // armazenar valor
	Node(int i, float v); //construtor
};

class Edge { // armazenar
public:
	int from;
	int to;
	float val;
	Edge(int f, int t, float v);
};

class GreaterEdge {
public:
	bool operator()(Edge e1, Edge e2); // min_heap
};
