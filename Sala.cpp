/*
 * sala.cpp
 *
 *  Created on: 23/05/2017
 *      Author: cande
 */

#include "Sala.h"

//Construtor com inicialização de valores por defeito
Sala::Sala() {
	this->codigoSala = 0;
	// TODO Auto-generated constructor stub

}

//Sobrecarga de construtor para inserção automatica de elementos
Sala::Sala(int codigoSala)
{
	this->codigoSala = codigoSala;
}

Sala::~Sala() {
	// TODO Auto-generated destructor stub
}

//Get's & Set's
int Sala::getCodigoSala() const
{
	return this->codigoSala;
}

void Sala::setCodigoSala(int codigo)
{
	this->codigoSala = codigo;
}

//metodo virtual sem implementação.
void Sala::inserirDados()
{

}
