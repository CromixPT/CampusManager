/*
 * Funcionario.cpp
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#include "Funcionario.h"

//Construtor de Funcionario, com inicialização de valores por defeito.
Funcionario::Funcionario() {
	this->numFuncionario = 0;
	this->numIdentificao = 0;
	this->salario=0;

}

//Sobrecarga de Construtor para inserção automatica de Funcionarios Administrativos
Funcionario::Funcionario(int numFuncionario, string nome, int numID,string morada, float salario)
{
	this->numFuncionario = numFuncionario;
	this->nome = nome;
	this->numIdentificao = numID;
	this->morada = morada;
	this->salario=salario;
}

//Sobrecarga de Construtor para inserção automatica de Funcionarios não Administrativos
Funcionario::Funcionario(int numFuncionario, string nome, int numID,string morada)
{
	this->numFuncionario = numFuncionario;
	this->nome = nome;
	this->numIdentificao = numID;
	this->morada = morada;
	this->salario=0;
}

Funcionario::~Funcionario() {
	// TODO Auto-generated destructor stub
}

// Get's & Set's da classe
string Funcionario::getNome() const
{
	return this->nome;
}

int Funcionario::getNumFuncionario() const
{
	return this->numFuncionario;
}

int Funcionario::getNumIdentificao() const
{
	return this->numIdentificao;
}

string Funcionario::getMorada() const
{
	return this->morada;
}

void Funcionario::setNome(string nome)
{
	this->nome = nome;
}

void Funcionario::setNumFuncionario(int numero)
{
	this->numFuncionario = numero;
}

void Funcionario::setNumIdentificao(int numero)
{
	this->numIdentificao = numero;
}

void Funcionario::setMorada(string morada)
{
	this->morada  = morada;
}

float Funcionario::getSalario(){
	return this->salario;
}

// Fim de Get's & Set's
