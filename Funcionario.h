/*
 * Funcionario.h
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <iostream>
using namespace std;

class Funcionario {
protected:
	int numFuncionario;
	string nome;
	int numIdentificao;
	string morada;
	float salario;
public:
	//Construtores
	Funcionario();
	Funcionario(int numFuncionario, string nome, int numID,string morada, float salario);
	Funcionario(int numFuncionario, string nome, int numID,string morada);
	//Destrutores
	virtual ~Funcionario();
	//Get's & Set's
	int getNumFuncionario() const;
	string getNome() const;
	int getNumIdentificao() const;
	string getMorada() const;
	void setNumFuncionario(int numero);
	void setNome(string nome);
	void setNumIdentificao(int numero);
	void setMorada(string morada);
	//Metodos virtuais da classe para serem implementados nas "subclasses"
	virtual float getSalario();
	virtual void inserirDados();
};


#endif /* FUNCIONARIO_H_ */
