#include <concepts>				// totalmente ordenavel
#include <iostream>
//#include "BinarySearchTree.h"

template<std::totally_ordered T>				//definido para qualquer tipo totalmente ordenavel
class BinarySearchTree
{
	class BSTNode {								// estrutura que representa o n�
	public:
		T value;
		std::unique_ptr<BSTNode> left;			// unique_ptr - ponteiro que faz controle de mem�ria
		std::unique_ptr<BSTNode> right;

		BSTNode(T v) { value = v; }				// construtor para o n�, recebe valor do tipo T  e atribui o valor
	};


public:

	BinarySearchTree() {};						// construtor vazio

	InsertionInfo insert(T v) {
		return insert(v, root);

	}

	SearchInfo search(T v) {					// m�todo search que retorna SearchInfo
		return search(v, root);
	}

	void print() {								// imprime a arvore
		return print(root);

	}

private:										// usu�rio nao pode acessar os n�s individualmente

	std::unique_ptr<BSTNode> root;				// n� raiz, ponteiro que aponta p raiz onde a �rvore come�a

	InsertionInfo insert(T v, std::unique_ptr<BSTNode>& node) {
		if (!node) {												// verifica se o o n� esta apontando para algo
			node = std::make_unique<BSTNode>(v);					// se a referencia estiver vazia, cria o n�
			return InsertionInfo::Inserted;
		}
		else if (v == node->value) {								// se o n� tiver apontando para algo, comparar valores
			return InsertionInfo::AlreadyIn;
		}
		else {
			return (v < node->value) ? insert(v, node->left) : insert(v, node->right);		// estrutura tern�rio
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