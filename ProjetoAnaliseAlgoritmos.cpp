// ProjetoAnaliseAlgoritmos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//


#include <vector>
#include <iostream>
#include <list>

#include "Utils.h"
#include "Utils.cpp"
#include "BruteForce.h"
#include "BruteForce.cpp"
#include "Students.cpp"
#include "GraphSearch.h"
#include "GraphSearch.cpp"
//#include "PermSetGenerators.h"
//#include "ConvexHull.h"
//#include "TopologicalSorting.h"

//===================== Brute Force  - Selection Sort  =================//

/* 
int main() {

	std::vector<int> v = { { 8,7,1,4,2 } };			// poderia alterar de vector para list, ou int para double

	printSequence(v);

	selection_sort(v);

	printSequence(v);
}
*/

//===================== Students ====================//

/*
int main() {

	std::vector<Student> v({});						// passando lista vazia no vetor
	
	v.push_back(Student("C", 10));					// inserindo elementos no vetor
	v.push_back(Student("B", 5));
	v.push_back(Student("B", 7));
	v.push_back(Student("A", 8));
	v.push_back(Student("F", 2));
	v.push_back(Student("E", 9));
	
	printSequence(v);

	//selection_sort(v.begin(), v.end());
	selection_sort(v.begin(), v.end(), compStudentNames());		 //definimos o comparador para nome

	printSequence(v);
}
*/


//=====================  GraphSearch  ====================//

int main{
	// representar como um vector de vectors
	std::vector<std::vector<int>> G({			// G é grafo e em cada linha tem os nós vizinhos daquele nó

		{1,2},
		{3,4},
		{5},
		{},
		{},
		{6,7},
		{8},
		{},
		{9},
		{} });

	std::list<int> pathdfs = dfs(0, G);		// os nós como listas de inteiros, pathdfs = caminho de busca de profundidade
											// dfs vai começa no nó 0 e explora o grafo completo
	printSequence(pathdfs);
}


/*
int main()
{
	std::vector<std::vector<int>> G({
		{0,1,0,0,1},
		{0,0,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{0,1,0,0,0} });

	std::list<int> sorted_nodes = topologicalSorting(G);

	printSequence(sorted_nodes);

}
*/