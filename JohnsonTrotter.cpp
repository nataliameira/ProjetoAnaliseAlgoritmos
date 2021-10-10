// JohnsonTrotter.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
// Guilherme Daher <https://github.com/daher13/paa/blob/main/johnsonTrotter.cpp>


#include <iostream>
#include <vector>
#include "Utils.h"

void revert(std::vector<int>& permutation, int mobile) {
    for (int& element : permutation) {
        if (abs(element) > abs(mobile)) {
            element *= -1;
        }
    }
}

int getMobile(std::vector<int> permutation) {           // função que encontra o elemento mobile
    std::vector<int> mobileList;                        // lista de todos os possíveis mobiles antes de comparar

    for (size_t i = 0; i < permutation.size(); i++) {
        if (permutation[i] < 0 && i > 0) {              // elemento apontado para ESQUERDA
            if (abs(permutation[i]) > abs(permutation[i - 1])) {  // se for maior que o anterior
                mobileList.push_back(i);                           // add na lista de possiveis mobiles
            }
        }
        else if (permutation[i] > 0 && i + 1 < permutation.size()) {  //elemento apontado para DIREITA
            if (abs(permutation[i]) > abs(permutation[i + 1])) {        // se for maior que o POSTERIOR
                mobileList.push_back(i);
            }
        }
    }

    if (mobileList.size() > 0) {
        int greater = mobileList[0];

        for (auto mobile : mobileList) {
            if (abs(permutation[mobile]) > abs(permutation[greater])) {
                greater = mobile;
            }
        }
        return greater;
    }

    return -1;
}

std::vector<std::vector<int>> johnsonTrotter(int n) {
    std::vector<int> permutation;
    std::vector<std::vector<int>> permutationList;

    for (int i = 1; i <= n; i++) {
        permutation.push_back(-i);
    }

    permutationList.push_back(permutation);

    while (true) {
        int k = getMobile(permutation);

        if (k < 0)
            break;
        int mobile = permutation[k];

        if (permutation[k] < 0) {  // LEFT
            std::swap(permutation[k], permutation[k - 1]);
        }
        else {  // RIGHT
            std::swap(permutation[k], permutation[k + 1]);
        }

        revert(permutation, mobile);
        permutationList.push_back(permutation);
    }

    return permutationList;
}