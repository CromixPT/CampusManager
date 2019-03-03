/*
 * Professor.h
 *
 *  Created on: 22/05/2017
 *      Author: cande
 */

#ifndef PROFESSOR_H_
#define PROFESSOR_H_


#include "Funcionario.h"
#include "Departamento.h"

enum CATEGORIA {Catedratico, Associado, Assistente};
static const  string catValues[] = {"Catedratico","Associado","Assistente"};

namespace std {

class Professor: public Funcionario {
private:
	CATEGORIA cat;
	Departamento departamento;
public:
	//Construtores
	Professor();
	Professor(int numFuncionario,string nome,int numID,string morada,CATEGORIA cat,Departamento* departamento);
	//Destrutor
	virtual ~Professor();
	//Get's & Set's
	string getCategoriaString() const;
	Departamento getDepartamento() const ;
	void setDepartamento(Departamento *departamento);
	//Metodos da classe
	void inserirDados();
};

} /* namespace std */

#endif /* PROFESSOR_H_ */
