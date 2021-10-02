#include <string>
// definir o estudante com 2 atributos: nome e nota
#include<iostream>

//============= Ordena Students por nota =====================//

class Student {
public:																		// método public: Ao preceder uma lista de membros de classe, a public palavra-chave especifica 
																					// que esses membros são acessíveis de qualquer função

	std::string name;
	float grade;
																			// construtor: personaliza como os membros de classe são inicializados ou invoca funções quando um 
																			// objeto de sua classe é criado. Um construtor tem o mesmo nome que a classe e nenhum valor de retorno.
	Student(std::string name, float grade) {
		this->name = name;
		this->grade = grade;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& st) {	// método que reescreve o operador << .Quando chamar o operador << para o tipo student, imprimirá o "nome : grade"
		os << "STDT" << st.name << ": " << st.grade;
		return os;															// os = output string
	}

	bool operator < (const Student& st) const								// const quer dizer que é constante e que o método não pode alterar o conteúdo desse objeto
																			//esse operador executa quem ta chamando ele e recebe student como parametro
	{
		return grade < st.grade;											// um estudante vai ser menor quando a nota for menor
	}
};

//============= Ordena Students por nome =====================//

// se eu quisesse ordenar por nome ao invés de nota, poderíamos redefnir o operador de menor da linha 30,
//									mas é possível com a definição que já fizemos
// então vamos definir um novo comparador, que também vai ser um comparador


class compStudentNames {
public:
	bool operator()(Student& s1, Student& s2) {		//método operator que recebe 2 estudantes
		return (s1.name < s2.name);						// e agora compara por nomes, com operador definido p strings, ordem alfabética, lexográfica
	}
};
