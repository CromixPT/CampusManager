/*
 * MenuClass.h
 *
 *  Created on: 27/05/2017
 *      Author: cande
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <iomanip>

using namespace std;

//Enum usado para definição do estado do menu, permite uma forma mais clara de mudar de estados.
//Evita a utilização de magic numbers: https://en.wikipedia.org/wiki/Magic_number_(programming)#Magic_numbers_in_other_uses
enum estadoMenu{Principal,Pessoal,Departamentos,Salas,Sair};

class Menu{
private:
	estadoMenu estado;
public:
	//Construtor
	Menu(estadoMenu estado);
	//Destrutor
	virtual ~Menu();
	//Set's & Get's
	void setEstado(estadoMenu estado);
	estadoMenu getEstado() const;
	//Metodos da classe
	int escolherMenu();
	void desenhaCabecalho(string string1);
	void desenhaOpcoes(string op1,string op2,string op3,string op4,string op5,string op6,string op7,string op8,string op9,string op10,string op11);
	void limparEcra();
};

#endif /* MENU_H_ */

