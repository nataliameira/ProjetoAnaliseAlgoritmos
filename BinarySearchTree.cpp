#include <concepts>				// totalmente ordenavel
#include <iostream>
//#include "BinarySearchTree.h"

template<std::totally_ordered T>				//definido para qualquer tipo totalmente ordenavel
class BinarySearchTree
{
	class BSTNode {								// estrutura que representa o nó
	public:
		T value;
		std::unique_ptr<BSTNode> left;			// unique_ptr - ponteiro que faz controle de memória
		std::unique_ptr<BSTNode> right;

		BSTNode(T v) { value = v; }				// construtor para o nó, recebe valor do tipo T  e atribui o valor
	};


public:

	BinarySearchTree() {};						// construtor vazio

	InsertionInfo insert(T v) {
		return insert(v, root);

	}

	SearchInfo search(T v) {					// método search que retorna SearchInfo
		return search(v, root);
	}

	void print() {								// imprime a arvore
		return print(root);

	}

private:										// usuário nao pode acessar os nós individualmente

	std::unique_ptr<BSTNode> root;				// nó raiz, ponteiro que aponta p raiz onde a árvore começa

	InsertionInfo insert(T v, std::unique_ptr<BSTNode>& node) {
		if (!node) {												// verifica se o o nó esta apontando para algo
			node = std::make_unique<BSTNode>(v);					// se a referencia estiver vazia, cria o nó
			return InsertionInfo::Inserted;
		}
		else if (v == node->value) {								// se o nó tiver apontando para algo, comparar valores
			return InsertionInfo::AlreadyIn;
		}
		else {
			return (v < node->value) ? insert(v, node->left) : insert(v, node->right);		// estrutura ternário
		}
	}

	SearchInfo search(T v, std::unique_ptr<BSTNode>& node) {
		if (!node) {
			return SearchInfo::NotFound;
		}

		if (v == node->value) {
			return SearchInfo::Found;
		}
		else {

			if (v < node->value) {
				return search(v, node->left);
			}
			else {
				return search(v, node->right);
			}
		}

	}

	void print(std::unique_ptr<BSTNode>& node) {
		if (!node) {
			return;
		}

		print(node->left);
		std::cout << node->value << "\t";
		print(node->right);
	}
};