#pragma once
#include<list>

//definir a assinatura do método

std::list<int> dfs(int, std::vector<std::vector<int>>);		// busca em profundidade
std::list<int> bfs(int, std::vector<std::vector<int>>);		// busca em largura