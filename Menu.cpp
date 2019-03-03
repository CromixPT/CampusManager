/*
 * MenuClass.cpp
 *
 *  Created on: 27/05/2017
 *      Author: cande
 */

#include "Menu.h"

//Construtor que recebe logo o estado inicial (Principal)
Menu::Menu(estadoMenu estado)
{
	this->estado = estado;
}

Menu::~Menu()
{

}

//Set's & Get's
void Menu::setEstado(estadoMenu estado)
{
	this->estado = estado;
}

estadoMenu Menu::getEstado() const
{
	return this->estado;
}

//Metodo que faz o display visual do menu, e recolhe a opção do utilizador.
//É retornada a informação para o main()
int Menu::escolherMenu()
{
	int op;
	switch(this->estado)
	{
	case Principal:
		desenhaCabecalho("Menu Principal");
		desenhaOpcoes("Gestao de Pessoal","Gestao de Departamentos", "Gestao de Salas","Sair","","","","","","","");
		break;
	case Pessoal:
		desenhaCabecalho("Gestao Pessoal");
		desenhaOpcoes("Novo Professor","Novo Administrativo","Listar Professores","Listar Administrativos","Apagar Professor","Apagar Administrativo","Calcular Total de Salarios","Calcular Salarios Professores","Calcular Salarios Administrativos","Salvar dados em ficheiro","Menu Anterior");
		break;
	case Departamentos:
		desenhaCabecalho("Gestao Departamentos");
		desenhaOpcoes("Novo Departamento","Listar Departamentos","Apagar Departamentos","Lista Professores do departamento","Menu Anterior","","","","","","");
		break;
	case Salas:
		desenhaCabecalho("Gestao Salas");
		desenhaOpcoes("Novo Gabinete","Nova Sala","Listar Gabinetes","Listar Salas","Apagar Gabinete","Apagar Sala","Menu Anterior","","","","");
		break;
	case Sair:
		break;
	}
	cin >>op;
	return op;
}



//Representação visual do cabeçalho do menu
void Menu::desenhaCabecalho(string string1){
	cout << "\n" ;
	cout<<setfill('*')<<setw(50)<< right <<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(15)<< " " << setw(22)<<left << string1 <<setw(12)<<right << "*" << endl;
	cout<<setfill('*')<<setw(50)<< right <<"*"<<endl;
}


//Limpa ecran para dar a ilusão de um novo ecran.
void Menu::limparEcra(){
  cout << string(30, '\n' );
}

//Representação visual do menu
void Menu::desenhaOpcoes(string op1,string op2,string op3,string op4,string op5,string op6,string op7,string op8,string op9,string op10,string op11){
	if(op1 != "")
		cout  <<  setfill(' ') << setw(6) << left <<  "*"  <<  setw(3) <<  left << "1. "<<  setw(35)  << left << op1  << setw(6) << right  <<  "*"  <<  endl;
	if(op2 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "2. "<<  setw(35)  << left << op2  << setw(6) << right  <<  "*"  <<  endl;
	if(op3 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "3. "<<  setw(35)  << left << op3 << setw(6) << right  <<  "*"  <<  endl;
	if(op4 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "4. "<<  setw(35)  << left << op4  << setw(6) << right  <<  "*"  <<  endl;
	if(op5 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "5. "<<  setw(35)  << left << op5  << setw(6) << right  <<  "*"  <<  endl;
	if(op6 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "6. "<<  setw(35)  << left << op6 << setw(6) << right  <<  "*"  <<  endl;
	if(op7 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "7. "<<  setw(35)  << left << op7  << setw(6) << right  <<  "*"  <<  endl;
	if(op8 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "8. "<<  setw(35)  << left << op8  << setw(6) << right  <<  "*"  <<  endl;
	if(op9 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "9. "<<  setw(35)  << left << op9  << setw(6) << right  <<  "*"  <<  endl;
	if(op10 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "10. "<<  setw(35)  << left << op10  << setw(5) << right  <<  "*"  <<  endl;
	if(op11 != "")
		cout  <<  setw(6) << left <<  "*"  <<  setw(3) <<  left << "11. "<<  setw(35)  << left << op11 << setw(5) << right  <<  "*"  <<  endl;
	cout<<setfill('*')<<setw(50)<< right <<"*"<<endl;
	cout << "Indique uma opcao: " ;
}




