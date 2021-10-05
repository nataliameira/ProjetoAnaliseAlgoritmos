#include <vector>
#include <list>
#include <algorithm>
#include "Utils.h"
#include "PermSetGenerators.h"

//=====================  Permuta��o com Busca em Profundidade ====================//

// pode ser utilizado para o problema do caixeiro viajante: basta avaliar todos os caminhos gerados e escolher o menor


void permgen(int n) {										// par�metros do m�todo: n numero para realizar as permuta��es

	std::list<int> start({});								// implementar o caminho da fronteira, lista com n� inicial s												
	std::list<std::list<int>> frontier({ start });			// implementar a fronteira

	while (!frontier.empty()) {								// enquanto a fronteira n�o estiver vazio

		//printSequenceSequence(frontier);					// Utils.h, lista de listas, 2 loops

		std::list<int> path(frontier.back());				// faz uma c�pia do ultimo caminho da fronteira
		frontier.pop_back();								// agr retira o ultimo caminho sem retornar o elemento (pop_back)
		
		if (path.size() == n) {								// agora, o objetivo � alcan�ado qdo atingimos n permuta��es, ou seja, se tem tamanho n, chegou ao fim
			printSequence(path);
		}
		else {												// fornecer a lista dos elementos que faltam na permuta��o
			std::vector<int> todo({});						// elementos que tenho para acessar
				
			for (int i = n - 1; i >= 0; i--)				// 
			{
				bool contains = (std::find(path.begin(), path.end(), i) != path.end()); // find: verifica se cada elemento j� est� na lista
				// nesse caso, end() n�o aponta para o �ltimo elemento da lista e sim para o final da lista
				// compara com path.end(), se for diferente, o elemento esta dentro da lista
				
				if (!contains) {						
					todo.push_back(i);						// add na lista 
				}
			}

			for (auto e : todo) {
				std::list<int> new_path(path);
				new_path.push_back(e);
				frontier.push_back(new_path);
			}
		}
	}
}

//=====================  Permuta��es com bin�rio ====================//
// por exemplo, para o problema da mochila


void binsetgen(int n) {										// n�o precisa mais restringir					

	std::list<int> start({});								// podemos come�ar com vazio
	std::list<std::list<int>> frontier({ start });

	while (!frontier.empty()) {

		std::list<int> path(frontier.back());
		frontier.pop_back();

		if (path.size() == n) {								// crit�rio de parada: n
			printSequence(path);
		}
		else {
			std::vector<int> todo({ 1,0 });					// sempre insere 0 ou 1

			for (auto e : todo) {							// s� para na profundidade m
				std::list<int> new_path(path);
				new_path.push_back(e);
				frontier.push_back(new_path);
			}
		}

	}
}

	//======  Permuta��o - imprimir os itens e n�o os bin�rios =======//


void subsetgen(int n) {

	std::vector<int> start({});
	std::list<std::vector<int>> frontier({ start });

	while (!frontier.empty()) {

		std::vector<int> path(frontier.back());				// o caminho vai ser  vector p poder acessar posi��o, pois lista n�o acessa posi��o
		frontier.pop_back();

		if (path.size() == n) {
			for (size_t i = 0; i < path.size(); i++)		// varre o vetor de bin�rio, se tiver 1 na posi��o, imprimir o �ndice
			{
				if (path[i]) {								// se o path for 1, pq ja considera 1 verdadeiro e 0 falso
					std::cout << i << " ";					// imprimo o i
				}											// mas lista n�o tem acesso direto a uma posi��o []
			}
			std::cout << std::endl;
		}
		else {
			std::vector<int> todo({ 1,0 });

			for (auto e : todo) {
				std::vector<int> new_path(path);
				new_path.push_back(e);						// custo constante inserir no final p vetor
				frontier.push_back(new_path);
			}
		}
	}
}

//=====================  Permuta��es- Binary Reflected Gray Code ====================//

// usou lista porque precisa add o elemento na frente 
// no vector precisaria empurrar todo mundo

std::list<std::list<int>> reflectedGrayCode(int n) {		// lista
	std::list<std::list<int>> power_set;					// poderia ser vector
						
	if (n == 1) {
		power_set.push_back({ 0 });							// vazio				
		power_set.push_back({ 1 });		
		// proprio elemento
		//return power_set;
	}
	else {
		std::list<std::list<int>> L1 = reflectedGrayCode(n - 1);
		std::list<std::list<int>> L2 = L1;
		std::reverse(L2.begin(), L2.end());					// reverse: Inverte a ordem dos elementos no intervalo [first,last).

		for (std::list<int>& str : L1) {					// add 0 na frente dos elementos da L1
			str.emplace(str.begin(), 0);					// emplace insere novo elemento na posi��o
		}

		for (std::list<int>& str : L2) {
			str.emplace(str.begin(), 1);					// add 1 na frente dos elementos da L1
		}

		L2.insert(L2.begin(), L1.begin(), L1.end());		// insert: insere novos elementos antes do elemento na posi��o detectada
		power_set = L2;
	}

	return power_set;

}