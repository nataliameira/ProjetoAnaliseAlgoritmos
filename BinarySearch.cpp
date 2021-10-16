#include<iostream>
#include<vector>
#include<algorithm>

/*
BinarySearch(A[0..n − 1], K)

	Implementa pesquisa binária não recursiva
	Input: um array A [0..n - 1] classificado em ordem crescente e uma chave de pesquisa K
	Output: um índice do elemento da matriz que é igual a K ou -1 se não houver tal elemento

	l←0; r ←n − 1
		while l ≤ r do
		m <- [(l + r)/2]
		if K = A[m] return m
		else if K <A[m] r <- m − 1
		else l <- m + 1
	return −1
*/

void binary_search(int k, std::vector<int>& v) {

	sort(v.begin(), v.end());

	int l = v[0];
	int m;
	int r = v.size();

	while (l <= r) {
		m = ((l + r) / 2);

		if (k == v[m]) {
			std::cout << m << std::endl;
			break;
		}

		else {
			if (k < v[m]) {
				r = m - 1;
			}

			else {
				l = m + 1;
			}
		}

		std::cout << -1 << std::endl;
	}
	
}







