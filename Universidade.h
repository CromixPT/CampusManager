/*
 * Universidade.h
 *
 *  Created on: 22/05/2017
 *      Author: cande
 */

#ifndef UNIVERSIDADE_H_
#define UNIVERSIDADE_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "Departamento.h"
#include "Professor.h"
#include "Administrativo.h"
#include "SalaAulas.h"
#include "Gabinete.h"

using namespace std;

class Universidade {
private:
	//Vectores

	vector<Departamento*> departamentos;
	vector<Professor*> professores;
	vector<Administrativo*> administrativos;
	vector<SalaAulas*> salasAulas;
	vector<Gabinete*> gabinetes;

	//Iteradores dos vetores

	vector<Departamento*>::iterator itDpt;
	vector<Professor*>::iterator itProf;
	vector<Administrativo*>::iterator itAdmin;
	vector<SalaAulas*>::iterator itSL;
	vector<Gabinete*>::iterator itGab;
public:
	//Construtor
	Universidade();
	//Destrutor
	virtual ~Universidade();

	//Metodos para criaçao de objectos nos vetores com interação do utilizador
	void novoDepartamento();
	void novoProfessor();
	void novoGabinete();
	void novaSalaAulas();
	void novoAdministrativo();

	//Metodos paa criação de objectos nos vetores automaticamente, sem interção com o utilizador
	void novoDepartamento(string nome);
	void novoProfessor(int numFuncionario,string nome,int numID,string morada,CATEGORIA cat,Departamento* departamento);
	void novoGabinete(int codigoSala,int secretarias,bool administrativo, Departamento* departamento);
	void novaSalaAulas(int codigoSala,int numLugares);
	void novoAdministrativo(int numFuncionario,string nome,int numID,string morada,int anosServico);

	//Metodos para listagem dos varias vetores
	void listaDepartamento();
	void listaProfessor();
	void listaSalas();
	void listaGabinetes();
	void listaAdministrativos();

	//Metodos para apagar elementos
	void apagaProfessor(int &id);
	void apagaAdministrativo(int &id);
	void apagaDepartamento(int &id);
	void apagaSala(int &id);
	void apagaGabinete(int &id);

	//Metodos variados
	float salarioAdmin();
	float salarioTotal();
	float salarioProfessor();
	void listaProfDpt(int &id);
	void salvarFicheiro();
};


#endif /* UNIVERSIDADE_H_ */
