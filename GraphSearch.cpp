#include<list>
#include<vector>
#include<iostream>

#include"GraphSearch.h"
#include"Utils.h"

//=====================  Busca em Profundidade ====================//

std::vector<int> get_neighbors(int node, std::vector<std::vector<int>> G) {		 // definindo uma fun��o q retorna os vizinhos
	return G[node];
}


bool is_goal(int node) {													// definindo uma fun��o q diz q o n� 9 � o objetivo
	return (node == 9);
}


std::list<int> dfs(int s, std::vector<std::vector<int>> G) {				//assinatura do m�todo definida em .h

	std::list<int> start({s});								// implementar o caminho da fronteira, lista com n� inicial s												
	std::list<std::list<int>> frontier({start});				// implementar a fronteira

	while (!frontier.empty()) {								// enquanto a fronteira n�o estiver vazio

		printSequenceSequence(frontier);						// Utils.h
	
		std::list<int> path(frontier.back());				// faz uma c�pia do ultimo caminho da fronteira
	
		frontier.pop_back();								// agr retira o ultimo caminho sem retornar o elemento (pop_back)

		if (is_goal(path.back())) {							// verificar se ele � o objetivo. is_goal = fun��o que recebe o �ltimo n� do caminho (criamos)
			return path;
		}
	
		else {
			for (auto e: get_neighbors(path.back(), G)) {		// descobrir os vizinhos, criar m�todo q retorna uma lista com os vizinhos do ultimo n� (criamos)
			std::list<int> new_path(path);						// novo caminho que � c�pia do caminho que tiramos da fronteira
			new_path.push_back(e);								// novo caminho
			frontier.push_back(new_path);						// add no final da fronteira
			}
		}
	}
}

//=====================  Busca em Largura ====================//

std::list<int> bfs(int s, std::vector<std::vector<int>> G) {

	std::list<int> start({ s });
	std::list<std::list<int>> frontier({ start });

	while (!frontier.empty()) {

		printSequenceSequence(frontier);

		std::list<int> path(frontier.front());			//tira do inicio
		frontier.pop_front();

		if (is_goal(path.back())) {
			return path;
		}
		else {
			for (auto e : get_neighbors(path.back(), G)) {		// verifica se tem vizinhos
				std::list<int> new_path(path);					// cria noto caminho para cada vizinho
				new_path.push_back(e);
				frontier.push_back(new_path);			// insere no final
			}
		}
	}
}