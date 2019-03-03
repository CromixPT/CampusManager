/*
 * Departamento.h
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#ifndef DEPARTAMENTO_H_
#define DEPARTAMENTO_H_

#include <iostream>

using namespace std;

class Departamento {
private:
	string nome;
public:
	//Construtores
	Departamento();
	Departamento(string nome);
	//Destrutores
	virtual ~Departamento();
	//Get's & Set's
	void setNome(string nome);
	string getNome() const;
	//Metodos da Classe
	void inserirDados();
};

#endif /* DEPARTAMENTO_H_ */
