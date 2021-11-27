#pragma once

class Node {
public:
	int id;
	float val;
	Node(int i, float v);
};

class Edge {
public:
	int from;
	int to;
	float val;
	Edge(int f, int t, float v);
};

class GreaterEdge {
public:
	bool operator()(Edge e1, Edge e2);
};
