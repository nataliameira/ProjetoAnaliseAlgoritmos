#include<vector>
#include<iostream>

/*
	Soma de todos os elementos de um vetor:
		- busca exaustiva
		- diminuir para conquistar
		- dividir para conquistar
*/


void soma_buscaexaustiva(std::vector<int>& v) {

	int s = 0;

	for (size_t i = 0; i < v.size(); i++) {
		s = s + v[i];
	}

	std::cout << s << std::endl;
}


int soma_dimconq(std::vector<int>& v) {

	int n = v.size();

	std::vector<int> t;

	if (v.size() == 1) {
		return v[0];
	}

	int i;

	for (i = 0; i < v.size() - 1; i++) {
		t.push_back(v[i]);
	}

	return soma_dimconq(t) + v[n - 1];
}


int soma_divconq(std::vector<int>& v) {

	std::vector<int> t;
	std::vector<int> u;

	int n = v.size();

	if (v.size() == 1) {
		return v[0];
	}


	if (n > 1) {

		int i;

		for (i = 0; i < v.size() / 2; i++) {
			t.push_back(v[i]);
		}

		for (; i < v.size(); i++) {
			u.push_back(v[i]);
		}

	}

	return soma_divconq(t) + soma_divconq(u);

}