/*
 * Gabinete.h
 *
 *  Created on: 25/05/2017
 *      Author: cande
 */

#ifndef GABINETE_H_
#define GABINETE_H_

#include "Sala.h"
#include "Departamento.h"

class Gabinete: public Sala {
private:
	int numSecretarias;
	bool Administrativo;
	Departamento departamento;
public:
	//Construtores
	Gabinete();
	Gabinete(int codigoSala,int secretarias,bool administrativo, Departamento* departamento);
	//Destrutores
	virtual ~Gabinete();
	//Get's & Set's
	int getNumSecretarias() const;
	void setNumSecreterias(int lugares);
	bool getAdministrativo() const;
	void setAdministrativo(bool admin);
	Departamento getDepartamento() const;
	void setDepartamento(Departamento* departamento);
	//Metodos da Classe
	void inserirDados();
};

#endif /* GABINETE_H_ */
