#pragma once
#include<list>

//definir a assinatura do m�todo

std::list<int> dfs(int, std::vector<std::vector<int>>);		// busca em profundidade
std::list<int> bfs(int, std::vector<std::vector<int>>);		// busca em largura