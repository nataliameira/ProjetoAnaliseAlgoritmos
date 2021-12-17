#include <ostream>
#include "Elements.h"

=
Node::Node(int i, float v) { //Estrutura para representar os n�s do grafo
	id = i;
	val = v;
}

Edge::Edge(int f, int t, float v) { //Representa para representar arestas, precisa de dois n�s e valores
	from = f;
	to = t;
	val = v;
}

bool GreaterEdge::operator()(Edge e1, Edge e2) {
	return e1.val > e2.val;
}