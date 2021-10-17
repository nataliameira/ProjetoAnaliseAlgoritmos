#include <vector>

/*
Matrix Multiplication (A[0..n − 1, 0..n − 1], B[0..n − 1, 0..n − 1])

    Multiplica duas matrizes quadradas de ordem n pelo algoritmo baseado em definição
    Input: Duas matrizes n×n,  A e B
    Output: Matriz C = AB

    for i <- 0 to n-1
        for j <- 0 to n-1
            C[i,j] <- 0
                for k <-0 to n-1 do
                    C[i, j ] <- C[i, j ]+ A[i, k] ∗ B[k, j]
    return C
*/



std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    
    std::vector<std::vector<int>> C(A.size(), std::vector<int>(A.size()));

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            for (int k = 0; k < C.size(); k++) {
                C[i][j] += A[i][k] * A[k][j];
            }
        }
    }
    return C;
}