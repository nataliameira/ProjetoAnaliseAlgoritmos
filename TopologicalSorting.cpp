#include <list>
#include <vector>
#include "TopologicalSorting.h"

std::list<int> topological_sorting(std::vector<std::vector<int>> G) {

	std::list<int> sorted_nodes({});					// lista que ser� retornada com a sequencia correta
	std::list<int> nodes({});							// lista de n�s ativos 

	for (int i = 0; i < G.size(); i++){					// loop encadeado, cada 1 dos 5 elementos de G (vetores)
	
		nodes.push_back(i);								// lista nodes come�a com [0,1,2,3,4]
	}

	// Find source										// encontrar os fontes
	while (!nodes.empty()) {							// resolve enquanto tiver n�s

		bool is_source = true;

		for (int e : nodes)								// elemento - cada elemento de um vetor de G: coluna
		{
			is_source = true;

			for (int r : nodes)							// : declara��o de um membro na estrutura
			{											// fixa r que � coluna e percorre e que � linha
				if (G[r][e] != 0) {						// varre todas as linhas, se for 0, � fonte
					is_source = false;					// se for diferente de 0, n�o � fonte, sai.
					break;
				}
			}
			// pq esse if nao esta dentro do for?
			if (is_source) {							// se for fonte, add na lista
				sorted_nodes.push_back(e);
				nodes.remove(e);						// e agora remove do conjunto de n�s
				break;
			}
		}

		// se sair sem ser fonte, retorna lista vazia
		if (!is_source) {								
			return std::list<int>({});
		}
	}

	return sorted_nodes;

}