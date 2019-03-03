/*
 * Administrativo.h
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#ifndef ADMINISTRATIVO_H_
#define ADMINISTRATIVO_H_

#include "Funcionario.h"

class Administrativo: public Funcionario {
private:
	int anosServico;
public:
	//Construtores
	Administrativo();
	Administrativo(int numFuncionario,string nome,int numID,string morada,int anosServico);
	//Destrutor
	virtual ~Administrativo();
	//Set's & Get's
	void setAnosServico(int anos);
	int getAnosServico() const;
	//Metodos da classe
	float getSalario();
	void inserirDados();
};

#endif /* ADMINISTRATIVO_H_ */
