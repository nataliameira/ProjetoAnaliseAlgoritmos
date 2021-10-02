#include <string>
// definir o estudante com 2 atributos: nome e nota
#include<iostream>

//============= Ordena Students por nota =====================//

class Student {
public:																		// m�todo public: Ao preceder uma lista de membros de classe, a public palavra-chave especifica 
																					// que esses membros s�o acess�veis de qualquer fun��o

	std::string name;
	float grade;
																			// construtor: personaliza como os membros de classe s�o inicializados ou invoca fun��es quando um 
																			// objeto de sua classe � criado. Um construtor tem o mesmo nome que a classe e nenhum valor de retorno.
	Student(std::string name, float grade) {
		this->name = name;
		this->grade = grade;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& st) {	// m�todo que reescreve o operador << .Quando chamar o operador << para o tipo student, imprimir� o "nome : grade"
		os << "STDT" << st.name << ": " << st.grade;
		return os;															// os = output string
	}

	bool operator < (const Student& st) const								// const quer dizer que � constante e que o m�todo n�o pode alterar o conte�do desse objeto
																			//esse operador executa quem ta chamando ele e recebe student como parametro
	{
		return grade < st.grade;											// um estudante vai ser menor quando a nota for menor
	}
};

//============= Ordena Students por nome =====================//

// se eu quisesse ordenar por nome ao inv�s de nota, poder�amos redefnir o operador de menor da linha 30,
//									mas � poss�vel com a defini��o que j� fizemos
// ent�o vamos definir um novo comparador, que tamb�m vai ser um comparador


class compStudentNames {
public:
	bool operator()(Student& s1, Student& s2) {		//m�todo operator que recebe 2 estudantes
		return (s1.name < s2.name);						// e agora compara por nomes, com operador definido p strings, ordem alfab�tica, lexogr�fica
	}
};
