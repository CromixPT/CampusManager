//============================================================================
// Name        : efolioB.cpp
// Author      : TCandeias
// Version     :
// Copyright   : **TCandeias**
// Description : Uni Manage
//============================================================================

#include <iostream>
#include "Menu.h"
#include "Universidade.h"
#include "Headers_efolioB.h"
using namespace std;

int main() {
	//Inicialização do objecto menu no estado Principal, que faz display do menu
	//Principal ao utilizador
	Menu m(Principal);
	Universidade univ;
	int op;
	do
	{
		//metodo do objeto menu retorna a opção escolhida pelo o utilizador
		op = m.escolherMenu();

		//conforme o estado do menu é escolhida o metodo correspondente e feito o set
		//do novo estado do objecto menu, que permite apresentar os varios menus ao utilizador
	    switch(m.getEstado())
	    {
	    //É usado o enum criado para o Menu para verificar o estado atual do menu.
	      case Principal:
	    	  m.limparEcra();
	    	  m.setEstado(processarOpcaoPrincipal(op));
	    	  break;
	      case Pessoal:
	    	  m.limparEcra();
	    	  m.setEstado(processarOpcaoMenuPessoal(op,univ));
	    	  break;
	      case Departamentos:
	    	  m.limparEcra();
	    	  m.setEstado(processarOpcaoMenuDepartamentos(op,univ));
	    	  break;
	      case Salas:
	    	  m.limparEcra();
	    	  m.setEstado(processarOpcaoMenuSalas(op,univ));
	    	  break;
	      case Sair:
	    	  m.limparEcra();
	    	  m.setEstado(processarOpcaoPrincipal(op));
	    	  break;
	    }
	    //O ciclo termina quando a opção Sair for selecionada e o objecto menu atualizado para o estado correspondente
	  } while(m.getEstado()!=Sair);

	return 0;
}


//Metodo criado para criar uma pausa e aguarda que o utilizador pressione enter para continuar.
//Utilizado maioriamente no fim do display de cada lista
void pause()
{
	cout << "Pressione <ENTER> para continuar...";
	cin.clear();
	cin.sync();
	cin.get();
}




//Processamento da opção selecionada no menu principal
estadoMenu processarOpcaoPrincipal(int &opcao)
{
	switch(opcao)
		{
		case 1:
			return Pessoal;
		case 2:
			return Departamentos;
		case 3:
			return Salas;
		case 4:
			return Sair;
		default:
			return Principal;
		}
}

//Processamento da opção selecionada no menu Pessoal
estadoMenu processarOpcaoMenuPessoal(int &opcao,Universidade& univ)
{
	switch(opcao)
		{
			int op;
			case 1:
				univ.novoProfessor();
				break;
			case 2:
				univ.novoAdministrativo();
				break;
			case 3:
				univ.listaProfessor();
				pause();
				break;
			case 4:
				univ.listaAdministrativos();
				pause();
				break;
			case 5:
				univ.listaProfessor();
				cout << "Selecione ID do Professor a apagar: ";
				cin >> op;
				univ.apagaProfessor(op);
				break;
			case 6:
				cout << "Selecione ID do Administrativo a apagar: ";
				cin >> op;
				univ.apagaAdministrativo(op);
				break;
			case 7:
				cout << "Salario total de todos os funcionarios: " << univ.salarioTotal() << endl;
				break;
			case 8:
				cout << "Total de Salarios pagos aos Administrativos: " << univ.salarioProfessor() << endl;
				break;
			case 9:
				cout << "Total de Salarios pagos aos Administrativos: " << univ.salarioAdmin() << endl;
				break;
			case 10:
				univ.salvarFicheiro();
				cout << "Ficheiro guardado com sucesso..." << endl;
				break;
			case 11:
				return Principal;
			default:
				cout << "Opcao Invalida! Por favor escolha outra opcao..." << endl;
				break;
			}
	  return Pessoal;
}

//Processamento da opção selecionada no menu Departamentos
estadoMenu processarOpcaoMenuDepartamentos(int &opcao,Universidade& univ)
{
	switch(opcao)
	{
		int op;
		case 1:
			univ.novoDepartamento();
			break;
		case 2:
			univ.listaDepartamento();
			break;
		case 3:
			univ.listaDepartamento();
			cout << "Selecione ID do departamento a apagar: ";
			cin >> op;
			univ.apagaDepartamento(op);
			pause();
			break;
		case 4:
			univ.listaDepartamento();
			cout << "Selecione ID do departamento a listar: ";
			cin >> op;
			univ.listaProfDpt(op);
			pause();
			break;
		case 5:
			return Principal;
		default:
			cout << "Opcao Invalida! Por favor escolha outra opcao..." << endl;
			break;
	}
	return Departamentos;
}

//Processamento da opção selecionada no menu Salas
estadoMenu processarOpcaoMenuSalas(int &opcao,Universidade& univ)
{
	switch(opcao)
	{
		int op;
		case 1:
			univ.novoGabinete();
			break;
		case 2:
			univ.novaSalaAulas();
			break;
		case 3:
			univ.listaGabinetes();
			break;
		case 4:
			univ.listaSalas();
			break;
		case 5:
			univ.listaGabinetes();
			cout << "Selecione codigo de Gabinete: ";
			cin >> op;
			univ.apagaGabinete(op);
			break;
		case 6:
			univ.listaSalas();
			cout << "Selecione codigo de Sala: ";
			cin >> op;
			univ.apagaSala(op);
			break;
		case 7:
			return Principal;
			break;
		default:
			cout << "Opcao Invalida! Por favor escolha outra opcao..." << endl;
			break;
	}
	return Salas;
}
