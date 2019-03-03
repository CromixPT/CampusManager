/*
 * Departamento.cpp
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#include "Departamento.h"

//Construtor de Deparmento com inicilização de valores por defeito
Departamento::Departamento() {
	this->nome="";

}
//Sobrecarga do construtor para inserção automatica de departamentos
Departamento::Departamento(string nome)
{
	this->nome = nome;
}

Departamento::~Departamento() {
	// TODO Auto-generated destructor stub
}

//Get's & Set's
void Departamento::setNome(string nome)
{
	this->nome = nome;
}

string Departamento::getNome() const
{
	return this->nome;
}

// Fim de Get's & Set's


//Inserção de dados por parte do utilizador na criação de novo departamento.
void Departamento::inserirDados()
{
	cout << "******** Criacao de Departamentos ********" << endl;
	cout << "Indique nome de departamento: " << endl;
	cin.sync();
	getline(cin,this->nome);
}
