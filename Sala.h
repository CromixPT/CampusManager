/*
 * Sala.h
 *
 *  Created on: 23/05/2017
 *      Author: cande
 */

#ifndef SALA_H_
#define SALA_H_

#include "Departamento.h"

class Sala {
protected:
	int codigoSala;
public:
	//Construtores
	Sala();
	Sala(int codigoSala);
	//Destrutores
	virtual ~Sala();
	//Get's & Set's
	int getCodigoSala() const;
	void setCodigoSala(int codigo);
	//Metodos virtuais.
	virtual void inserirDados();
};

#endif /* SALA_H_ */
