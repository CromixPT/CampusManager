/*
 * Administrativo.cpp
 *
 *  Created on: 20/05/2017
 *      Author: cande
 */

#include "Administrativo.h"

//Construtor, inicializa com valores por defeito. Salario de administrativo inicializado com salario base.
Administrativo::Administrativo() {
	this->anosServico = 0;
	this->salario = 800;
}

// Sobrecarga do construtor da classe, para inserção automatica de objectos.
// Dado que é uma classe com uma herança, são passados os campos necessarios para a classe superior.
Administrativo::Administrativo(int numFuncionario,string nome,int numID,string morada,int anosServico) : Funcionario(numFuncionario,nome,numID,morada,800)
{
	this->anosServico = anosServico;
}

Administrativo::~Administrativo() {
	// TODO Auto-generated destructor stub
}



// Set's & Gets da Classe
void Administrativo::setAnosServico(int anos)
{
	this->anosServico = anos;
}

int Administrativo::getAnosServico() const
{
	return this->anosServico;
}

// Fim de Set's & Get's


//Calculo do salario de administrativo
float Administrativo::getSalario() {
	float total=this->salario;
	//Aumento é efetuado a cada 5 anos de servico.
	for(int i=1;i<=(this->anosServico/5);i++)
	{
		//aumento de 10% do salario atual.
		total *= 1.10;
	}
	return total;
}


//Inserção de dados pelo Utilizador para criação de novo Administrativo.
void Administrativo::inserirDados()
{
	cout << "\n*** Insercao de novo Funcionario Administrativo ***\n";
	cout << "Numero de Funcionario: ";
	cin >> this->numFuncionario;
	cout << "Indique nome: ";
	cin.ignore();
	getline(cin,this->nome);
	cout << "Numero de Identificacao: ";
	cin >> this->numFuncionario;
	cout << "Morada: ";
	cin.ignore();
	getline(cin,this->morada);
	cout << "Anos de servico: ";
	cin >> this->anosServico;
}

