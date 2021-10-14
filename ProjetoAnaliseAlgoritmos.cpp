// ProjetoAnaliseAlgoritmos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.


#include <vector>
#include <iostream>
#include <list>

#include"Utils.h"
//#include"BruteForce.h"
//#include "Students.cpp"
//#include"GraphSearch.h"
//#include"PermSetGenerators.h"
//#include "TopologicalSorting.h" 
//#include"BinarySearchTree.h"
//#include"JohnsonTrotter.cpp"
//#include "ConvexHull.h"

//#include"InsertionSort.h"
//#include"CommonElements.h"
//#include"EuclideanAlgorithmGCD.h"
//#include"Dmin.h"
//include"Fatorial.h"
//#include"Fibonacci.h"
#include"SequentialSearch2.h"

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

/* 
int main() {
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

	//std::list<int> pathbfs = bfs(0, G);		

	//printSequence(pathbfs);
}
*/


//======= PermSetGen - gerador de permutações   ========//


//int main() {

	//permgen(4);				// permutações

	//binsetgen(4);				// Binário

	//subsetgen(4);				// valores do binario, subconjuntos de itens

	//std::list<std::list<int>> sets = reflectedGrayCode(3);	// reflectedGrayCode

	//printSequenceSequence(sets);
	
//}



//======= Topological Sorting  ========//

/* 
int main(){ 

	std::vector<std::vector<int>> G({		// grafo G, poderia ser float ou double, p generalizar ou fazer com que as arestas tenham peso/custo
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{0,0,0,0,0} });

	std::list<int> sorted_nodes = topological_sorting(G);

	printSequence(sorted_nodes);

}
*/

//======= Binary Search Tree  ========//

/*
int main() {

	BinarySearchTree<int> bt;

	std::cout << (bt.insert(8) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;		// verificar se o valor foi inserido
	std::cout << (bt.insert(1) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(5) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(10) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(5) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(3) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(4) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;
	std::cout << (bt.insert(1) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << std::endl;

	bt.print();							// método print p o objeto bt

	std::cout << (bt.search(3) == SearchInfo::Found ? "Found" : "NotFound") << std::endl;		// buscando valores
	std::cout << (bt.search(100) == SearchInfo::Found ? "Found" : "NotFound") << std::endl;
}
*/

//======= Johnson Trotter  ========//
/* 
main(){

	std::vector<std::vector<int>> permutations = johnsonTrotter(5);

	for (auto permutation : permutations) {
		printSequence(permutation);
	}

	return 0;
}
*/

//===================== Insertion Sort  =================//

/*
int main() {

	std::vector<int> v = { { 8,7,1,4,2 } };			

	printSequence(v);

	insertion_sort(v);

	printSequence(v);
}
*/

//===================== Common Elements  =================//

/* 
int main() {

	std::vector<int> A = { { 2,5,5,5 } };
	std::vector<int> B = { { 2,2,3,5,5,7 } };

	printSequence(A);
	printSequence(B);

	common_elements(A, B);

}
*/

//===================== Euclidean Algorithm GCD  =================//

/* 
int main() {

	int n = 400;
	int m = 25;

	gcd(m, n);
}
*/

//===================== Dmin ===============//

/* 
int main() {

	std::vector<int> v = { { 10, 15, 32, 44, 51 } };

	printSequence(v);

	dist_min(v);

}
*/

//===================== Fatorial ===============//

/* 
int main() {

	int n = 5;

	//fatorial(n);

	std::cout << fatorial(n) << std::endl;

}
*/

//===================== Fibonacci ===============//

/* 
int main() {

	int n = 11;

	std::cout << fibonacci(n) << std::endl;

}
*/

/* 
//======= Simulado - Binary Search Tree  ========//


int main() {

	BinarySearchTree<int> bt;

	bt.insert(5); 		// verificar se o valor foi inserido
	bt.insert(3);
	bt.insert(7);
	bt.insert(1);
	bt.insert(4);
	bt.insert(6);
	bt.insert(10);

	bt.preorder();
	std::cout << std::endl;

	bt.inorder();
	std::cout << std::endl;

	bt.postorder();
	std::cout << std::endl;
}
*/
	
//======= SequentialSearch2 ========//


int main() {

	std::vector<int> v = { { 8, 14, 21, 34, 41, 57, 68, 72, 76 } };

	printSequence(v);

	int k = 41;

	seq_search2(v);

}







