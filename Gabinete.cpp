/*
 * Gabinete.cpp
 *
 *  Created on: 25/05/2017
 *      Author: cande
 */

#include "Gabinete.h"

//Construtor de classe com inicialização de valores por defeito
Gabinete::Gabinete() {
	// TODO Auto-generated constructor stub
	this->Administrativo = false;
	this->numSecretarias = 0;
}

//Sobrecarga de construtor para inserção automatica de novo Gabinete
Gabinete::Gabinete(int codigoSala,int secretarias,bool administrativo, Departamento* departamento) :Sala(codigoSala)
{
	this->numSecretarias= secretarias;
	this->Administrativo = administrativo;
	if(this->Administrativo == false)
		this->departamento = *departamento;
}

Gabinete::~Gabinete() {
	// TODO Auto-generated destructor stub
}

//Get's & Set's da classe
int Gabinete::getNumSecretarias() const
{
	return this->numSecretarias;
}

void Gabinete::setNumSecreterias(int lugares)
{
	this->numSecretarias = lugares;
}

bool Gabinete::getAdministrativo() const
{
	return this->Administrativo;
}

void Gabinete::setAdministrativo(bool admin)
{
	this->Administrativo = admin;
}

Departamento Gabinete::getDepartamento() const
{
	return this->departamento;
}

void Gabinete::setDepartamento(Departamento *departamento)
{
	this->departamento = *departamento;
}

// Fim de Get's & Set's


//Metodo para inserção de dados pelo Utilizador na criação de novo gabinete
void Gabinete::inserirDados()
{
	int op;
	cout << "\n*** Insercao de novo Gabinete ***\n";
	cout << "Indique codigo do gabinete: ";
	cin >>  this->codigoSala;
	cout << "Indique o numero de sercretarias: ";
	cin >> this->numSecretarias;
	cout << "Gabinte Administrativo?(1. Sim, 2.Nao)";
	do
	{
		cin >> op;
		if(op==1)
			this->Administrativo = true;
		else if(op==2)
			this->Administrativo = false;
	}while(op <1 || op>2);

}
