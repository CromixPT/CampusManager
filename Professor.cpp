/*
 * Professor.cpp
 *
 *  Created on: 22/05/2017
 *      Author: cande
 */

#include "Professor.h"

namespace std {

//Construtor da classe, com inicilizaçõa de categoria por defeito
Professor::Professor() {
	this->cat = Catedratico;
}

//Sobrecarga de construtor para introdução automatica de Professores
Professor::Professor(int numFuncionario,string nome,int numID,string morada,CATEGORIA cat,Departamento* departamento) : Funcionario(numFuncionario,nome,numID,morada)
{
	this->cat = cat;
	this->departamento = *departamento;
	if(cat == 0)
		this->salario = 1500;
	else if(cat == 2)
		this->salario = 1200;
	else
		this->salario = 950;
}

Professor::~Professor() {
	// TODO Auto-generated destructor stub
}


//Insercação de dados para criação de novo professor
void Professor::inserirDados()
{
	int op;
	cout << "\n*** Insercao de novo Professor ***\n";
	cout << "Numero de Funcionario: ";
	cin >> this->numFuncionario;
	cout << "Indique nome: ";
	cin.sync();
	getline(cin,this->nome);
	cout << "Numero de Identificacao: ";
	cin >> this->numFuncionario;
	cout << "Morada: ";
	cin.ignore();
	getline(cin,this->morada);
	//Escolha da categoria através de um "mini" menu
	do
	{
		cout << "Indique Categoria(1.Catedratico, 2.Associado, 3.Assistente): ";
		cin >> op;
		if(op <1 && op >3)
			cout << "Selecione uma categoria valida...\n\n\n";
	}while(op <1 && op>3);

	this->cat = (CATEGORIA)(op-1);
	//Salario é fixo conforme a categoria
	if(this->cat== Catedratico)
		this->salario = 1500;
	else if(this->cat== Associado)
		this->salario = 1200;
	else
		this->salario = 950;
}

//Caso especifico de um Get da que interessa é fazer output do texto e não do indice do enum
//Assim com recurso a um vector de strings é feito o output do pretendeido
string Professor::getCategoriaString() const
{
	return catValues[this->cat];
}


Departamento Professor::getDepartamento() const
{
	return this->departamento;
}

void Professor::setDepartamento(Departamento *departamento)
{
	this->departamento = *departamento;
}

} /* namespace std */
