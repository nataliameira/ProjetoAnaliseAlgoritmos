#include<vector>
#include<concepts>

/*
Insertion Sort (A[0..n-1])
	Classifica um array por classificação de inserção
	Input: um array A[0..n-1] de n  elementos que podem ser solicitados
	Output: um array A[0..n-1] classificado em ordem não descrescente

	for i <- 1 to n-1 do
		v <- A[i]
		j <- i-1
		while j>=0 and A[j]>v do
			A[j+1] <- A[j]
			j <- j-1
			A[j+1] <- v
*/


template<typename T>																						

requires std::totally_ordered<T>						
														 
	void insertion_sort(std::vector<T>& v) {

	int i, j, element;

	for (size_t i = 1; i < v.size(); i++) {

		j = i - 1;
		T element = v[i];

		while (j >= 0 && v[j] > element) {
			std::swap(v[j + 1], v[j]);
			j--;
			v[j + 1] = element;
		};
	}
}