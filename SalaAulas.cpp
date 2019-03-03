/*
 * SalaAulas.cpp
 *
 *  Created on: 23/05/2017
 *      Author: cande
 */

#include "SalaAulas.h"


//Construtor com inicialização de valores por defeito
SalaAulas::SalaAulas() {
	this->numLugares = 0;
}

//Construtor para introdução automatica de dados.
SalaAulas::SalaAulas(int codigoSala,int numLugares) : Sala(codigoSala)
{
	this->numLugares = numLugares;
}

SalaAulas::~SalaAulas() {
	// TODO Auto-generated destructor stub
}

//Get's & Set's
int SalaAulas::getNumLugares() const
{
	return this->numLugares;
}

void SalaAulas::setNumLugares(int lugares)
{
	this->numLugares = lugares;
}


//Recolha de dados do utilizador para inserção de nova sala de aulas.
void SalaAulas::inserirDados()
{
	cout << "\n*** Insercao de nova Sala de Aulas ***\n";
	cout << "Numero de Sala: ";
	cin >> this->codigoSala;
	cout << "Numero de lugares: ";
	cin >> this->numLugares;
}
