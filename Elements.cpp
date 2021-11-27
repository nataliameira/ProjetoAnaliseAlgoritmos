#include <ostream>
#include "Elements.h"

Node::Node(int i, float v) {
	id = i;
	val = v;
}

Edge::Edge(int f, int t, float v) {
	from = f;
	to = t;
	val = v;
}

bool GreaterEdge::operator()(Edge e1, Edge e2) {
	return e1.val > e2.val;
}