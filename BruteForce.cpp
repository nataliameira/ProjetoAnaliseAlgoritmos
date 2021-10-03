#include<iostream>
#include <vector>
#include <algorithm>
#include <concepts>
#include <compare>
#include <set>
#include <functional>
#include <stack>
#include <list>
//#include"BruteForce.h"

// ============ Selection Sort - tipos ordenaveis ================= //
/*
template<typename T>									// template em que definimos o tipo: vetor
														// essa implementa��o n�o serve para qualquer tipo T, pois precisa ser compar�vel

requires std::totally_ordered<T>						// permite passar somente o que for totalmente ordenavel (concepts)	
														// tottaly_ordered: tipos totalmente ordenaveis que satisfaz as condi��es na referencia em que esta formalmente definido
void selection_sort(std::vector<T>& v) {
	int min;											// armazena indice do menor valor encontrado

	for (size_t i = 0; i < v.size() - 1; i++) {			// varre at� a ultima posi��o do vetor
														// o custo de saber o tamanho do vetor � ordem 1, pois se j� sabe o tamanho do vetor ent�o armazena esse tamanho
		min = i;
		for (size_t j = i+1; j < v.size(); j++) {			// n�o volta ao inicio, continua de i+1

			if (v[j] < v[min]){							// operador [] n�o esta definido para lista, para modificar pode-se trabalhar com iterator
				min = j;
			}
		}												// termina de percorrer as posi��es para saber qual � o min
	std::swap(v[i], v[min]);
	}
}

//c++20: introduziu concepts para lidar c a restri��o de iterar e comparar apenas n�meros
// remodelar o selection sort para a classe iterator
*/


// ============ Selection Sort - para outros tipos ================= //

template<typename T>
concept can_sort = requires(T u, T v) { u < v; };                    // criamos um conceito chamado "posso_ordenar" que recebe 2 vari�veis do msm tipo e possui opera��o u < v

template<typename T>

void selection_sort(std::vector<T>& v) requires can_sort<T> {       // o vetor T precisa implementar u < v, n�o precisa mais ser tottaly_ordered
    int min;                                                        // armazena o �ndice do menor valor encontrado

    for (size_t i = 0; i < v.size() - 1; i++)                       // m�todo size() pega o tamanho do vetor. Ent�o vai de 0 at� o tamanho do vetor.
    {
                                                                    // o custo de saber o tamanho do vetor � ordem 1, pois se j� sabe o tamanho do vetor ent�o armazena esse tamanho.

        min = i;                                                    // assumindo que est� na primeira posi��o
        for (size_t j = i + 1; j < v.size(); j++) {                 //olha da posi��o pra frente

            if (v[j] < v[min]) {                                    //essa opera��o n�o funcionaria para uma lista. Poderia trabalhar c a abstra��o classe iterator
                min = j;                                            // quando � menor, min recebe j e continua percorrendo o vetor

            }

        }
        std::swap(v[i], v[min]);                                    //troca as posi��es
    }

}

// Agora queremos implementar o iterator
// O template recebe duas classes: iterador e comparador
// serve, por exemplo, para iterar em ordem alfabetica


//============= Outra forma de implementar =====================//

template <class It, class C> void selection_sort(It first, It last, C comparator) { //recebe iterador p primeira posi��o, ultima posi��o e comparador

    for (auto it = first; it != last; ++it) {
        iter_swap(it, std::min_element(it, last, comparator));                      // m�todo iter_swap: troca valores passando iteradores, faz o for interno. min_element � um m�todo.
    }
}


//============= Outra forma de implementar =====================//
template <class It> void selection_sort(It first, It last) {                        // se o usu�rio n�o passar o comparador, o comparador vai se o menor que (classe less)

    for (auto it = first; it != last; ++it) {
        iter_swap(it, std::min_element(it, last, std::less<std::decay_t<decltype(*first)>>())); //decltype descobre o tipo para o qual estamos apontando
        // exemplo: decay_t faz com que a referencia aponte pro inteiro se o tipo for inteiro
    }
}


// ============ Bubble Sort ================= //

template <typename T>
void bubble_sort(std::vector<T>& v) {
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = 0; j < v.size() - 1 - i; j++)
		{
			if (v[j] > v[j + 1]) {
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

template <class It, class C> void bubble_sort(It first, It last, C comparator)
{
	// std::vector<T>::iterator
	for (auto it = first; it != last - 1; ++it)
	{
		for (auto it2 = first; it2 != (last - (it - first) - 1); ++it2) {
			iter_swap(it2, std::min_element(it2, it2 + 2, comparator));
		}
	}
}

template <class It> void bubble_sort(It first, It last)
{
	bubble_sort(first, last, std::less<std::decay_t<decltype(*first)>>());
}