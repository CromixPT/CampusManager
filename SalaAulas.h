/*
 * SalaAulas.h
 *
 *  Created on: 23/05/2017
 *      Author: cande
 */

#ifndef SALAAULAS_H_
#define SALAAULAS_H_


#include "Sala.h"

using namespace std;

class SalaAulas: public Sala {
private:
	int numLugares;
public:
	//construtores
	SalaAulas();
	SalaAulas(int codigoSala,int numLugares);

	//destrutrutor
	virtual ~SalaAulas();
	// Get's & Set's
	int getNumLugares() const;
	void setNumLugares(int lugares);
	// Metodos da classe
	void inserirDados();
};

#endif /* SALAAULAS_H_ */
