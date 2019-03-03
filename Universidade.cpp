/*
 * Universidade.cpp
 *
 *  Created on: 22/05/2017
 *      Author: cande
 */

#include "Universidade.h"

// Utilização do construtor da Classe universidade para criação dos varios objectos que existem pre-carregados
// no programa
Universidade::Universidade() {

	//Criação de novos departamentos
	novoDepartamento("Informatica");
	novoDepartamento("Psicologia");
	novoDepartamento("Matematica");
	novoDepartamento("C. Sociais");

	//Novos funcionarios administrativos
	novoAdministrativo(1,"Rui Veloso",123001,"Rua das Estrelas",10);
	novoAdministrativo(2,"Dulce Pontes",123002,"Rua das Cenouras",12);
	novoAdministrativo(3,"Pedro Abrunhosa",123003,"Rua das Batatas",25);
	novoAdministrativo(4,"Rita Guerra",123004,"Rua do Fado",2);

	//Inserção de novos professores, com utilização da enumeração de categoria.
	novoProfessor(5,"Alvaro de Campos",123005,"Rua do Tabaco",Catedratico,departamentos[0]);
	novoProfessor(6,"Ricardo Reis",123006,"Rua da Brasuca",Associado,departamentos[1]);
	novoProfessor(7,"Alberto Caeiro",123007,"Rua do pirolito",Assistente,departamentos[2]);
	novoProfessor(8,"Bernardo Soares",123008,"Rua do maluco",Catedratico,departamentos[3]);
	novoProfessor(9,"Fernando Pessoa",123009,"Rua do genio",Associado,departamentos[0]);
	novoProfessor(10,"Miguel Torga",123010,"Rua do pastel",Assistente,departamentos[1]);
	novoProfessor(11,"Gil Vicente",123007,"Rua do Alecrim",Catedratico,departamentos[2]);

	//Criação de Gabinetes
	novoGabinete(1,2,false,departamentos[0]);
	novoGabinete(2,4,true,departamentos[0]);
	novoGabinete(3,2,false,departamentos[1]);
	novoGabinete(4,5,true,departamentos[1]);
	novoGabinete(5,2,false,departamentos[2]);
	novoGabinete(6,2,false,departamentos[3]);


	//Criação de Salas de aulas
	novaSalaAulas(7,150);
	novaSalaAulas(8,175);
	novaSalaAulas(9,120);
	novaSalaAulas(10,75);
	novaSalaAulas(11,115);

}

//Destrutor de Universidade()
Universidade::~Universidade() {
	//Libertação dos elementos do vector departamentos;
	for(itDpt=departamentos.begin();itDpt!=departamentos.end();++itDpt)
		delete (*itDpt);
	//Libertação dos elementos do vector Professores;
	for(itProf=professores.begin();itProf!=professores.end();++itProf)
		delete(*itProf);
	//Libertação dos elementos do vector Administrativos;
	for(itAdmin=administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
		delete(*itAdmin);
	//Libertação dos elementos do vector SalasAulas;
	for(itSL=salasAulas.begin();itSL!=salasAulas.end();++itSL)
		delete(*itSL);
	//	//Libertação dos elementos do vector Gabinetes;
	for(itGab=gabinetes.begin();itGab!=gabinetes.end();++itGab)
		delete(*itGab);
}


//Inserção de novo professor com utilização de ponteiro para a classe Professor.
void Universidade::novoProfessor()
{
	int op;
	Professor* nProfessor = new Professor;
	nProfessor->inserirDados();
	cout << "Selecione um departamento para inserir o Professor:" << endl;
	listaDepartamento();
	cin >> op;
	nProfessor->setDepartamento(departamentos[op-1]);
	this->professores.push_back(nProfessor);
}

//Sobrecarga do metodo novoProfessor para permitir a inserção automatica de Professores.
void Universidade::novoProfessor(int numFuncionario,string nome,int numID,string morada,CATEGORIA cat,Departamento* departamento)
{
	Professor* nProfessor = new Professor(numFuncionario,nome,numID,morada,cat,departamento);
	this->professores.push_back(nProfessor);
}

//Listage de todos os elementos do vector professor
void Universidade::listaProfessor()
{
	//Criação da moldura visual da listagem.
    cout<<setfill('*')<<setw(116)<<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(37)<< " " << setw(26) << "Listagem geral Professores" << setfill(' ')<<setw(52) << "*" << endl;
	cout <<setfill('*')<<setw(116)<<"*"<<endl;
	cout << setfill(' ') << "*";
    cout << setw(10) << "ID Func" << setw(2)<< "*";
	cout << setw(19) << "Nome" << setw(16)<< right<< "*";
	cout << setw(6)<< "ID"<< setw(5)<< right<< "*";
	cout << setw(14) << "Morada" << setw(10)<< right<< "*";
	cout << setw(14) << "Departamento" << setw(3)<< right<< "*";
    cout << setw(11) << "Categoria" << setw(5)<< right<< "*"<< endl;
	cout<<setfill('*')<<setw(116)<<"*"<<endl;
	//Utilização do iterador para precorrer todo o vetor Professores
	for(this->itProf=this->professores.begin();this->itProf!=this->professores.end();++itProf)
	{
		//output dos elementos relevantes atraves do iterador.
		//(*itProf) permite acesso ao objecto
		cout <<setfill(' ')  << setw(6)<<left << "*";
		cout << setw(6) <<  (*itProf)->getNumFuncionario()<< setw(13)<<left << "*";
		cout << setw(22)<<  (*itProf)->getNome()<< setw(3)<<left<<"*";
		cout << setw(8) <<  (*itProf)->getNumIdentificao() << setw(5)<<left << "*";
		cout << setw(19) <<  (*itProf)->getMorada()<< setw(4)<<left << "*";
		cout << setw(13) << (*itProf)->getDepartamento().getNome() <<setw(3)<<left << "*";
        cout << setw(13) << (*itProf)->getCategoriaString() << "*"<< endl;
	}
	cout<<setfill('*')<<setw(116)<<"*"<<endl;

}

//Criação de novos departamentos com recurso a ponteiro para Departamento.
void Universidade::novoDepartamento()
{
	Departamento* nDepartamento  = new Departamento;
	nDepartamento->inserirDados();
	this->departamentos.push_back(nDepartamento);
}

//Sobrecarga do metodo para inserção automatica de departamentos
void Universidade::novoDepartamento(string nome)
{
	Departamento* nDepartamento  = new Departamento(nome);
	this->departamentos.push_back(nDepartamento);
}

//Listagem completa do vetor de departamentos
void Universidade::listaDepartamento()
{
	cout << "----------------Lista de Departamentos----------------" << endl;
	//Utilização do iterador do vector departamentos para percorrer todo o vetor.
	for(this->itDpt=this->departamentos.begin(); this->itDpt!=this->departamentos.end();++itDpt)
	{
		//Output do indice do vector + 1 para o utilizar poder selecionar departamento
		//da lista iniciando as opcoes em 1.
		cout << (itDpt-departamentos.begin())+1 << ". " << (*itDpt)->getNome() << endl;
	}
	cout << "------------------------------------------------------" << endl;
}

//Criação de novas salas de aulas com recurso a ponteiro para SalaAulas.
void Universidade::novaSalaAulas()
{
	SalaAulas* nSala = new SalaAulas;
	nSala->inserirDados();
	this->salasAulas.push_back(nSala);
}

//Metodo para inserção automatica de salas de aulas.
void Universidade::novaSalaAulas(int codigoSala,int numLugares)
{
	SalaAulas* nSala = new SalaAulas(codigoSala,numLugares);
	this->salasAulas.push_back(nSala);
}

//Listagem completa do vetor de SalasAulas
void Universidade::listaSalas()
{

    cout<<setfill('*')<<setw(75)<<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(27)<< " " << setw(20) << "Listagem geral Salas" << setfill(' ')<<setw(27) << "*" << endl;
	cout <<setfill('*')<<setw(75)<<"*"<<endl;
	cout << setfill(' ') << "*";
    cout << setw(17) << "Codigo de Sala" << setw(4)<< "*";
	cout << setw(37) << "Numero total de lugares" << setw(16)<< right<< "*"<< endl;
	cout<<setfill('*')<<setw(75)<<"*"<<endl;
	for(this->itSL = this->salasAulas.begin(); this->itSL!= this->salasAulas.end();++itSL)
	{
		cout <<setfill(' ')  << setw(9)<<left << "*";
		cout << setw(12) << (*itSL)->getCodigoSala()<< setw(25)<<left << "*";
        cout << setw(28) << (*itSL)->getNumLugares() << "*"<< endl;
	}
	cout<<setfill('*')<<setw(75)<<"*"<<endl;
}

//Criação de novas salas de aulas com recurso a ponteiro para Gabinete.
void Universidade::novoGabinete()
{
	int op;
	Gabinete* nGabinete = new Gabinete;
	nGabinete->inserirDados();
	if(!nGabinete->getAdministrativo())
	{
		listaDepartamento();
		cin >> op;
		nGabinete->setDepartamento(departamentos[op-1]);
	}
	this->gabinetes.push_back(nGabinete);
}

//Inserção automatica de elementos no vetor Gabinetes.
void Universidade::novoGabinete(int codigoSala,int secretarias,bool administrativo, Departamento* departamento)
{
	Gabinete* nGabinete = new Gabinete(codigoSala,secretarias,administrativo,departamento);
	this->gabinetes.push_back(nGabinete);
}


//Listagem completa do vetor Gabinetes
void Universidade::listaGabinetes()
{
    cout<<setfill('*')<<setw(116)<<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(38)<< " " << setw(24) << "Listagem geral Gabinetes" << setfill(' ')<<setw(53) << "*" << endl;
	cout <<setfill('*')<<setw(116)<<"*"<<endl;
	cout << setfill(' ') << "*";
    cout << setw(17) << "Codigo de Sala" << setw(5)<< "*";
	cout << setw(31) << "Numero de secretarias" << setw(11)<< right<< "*";
	cout << setw(27)<< "Gabinete Administrativo"<< setw(5)<< right<< "*";
	cout << setw(15) << "Departamento" << setw(4)<< right<< "*"<< endl;
	cout<<setfill('*')<<setw(116)<<"*"<<endl;
	//Utilização do iterador para precorrer todo o vetor Professores
	for(this->itGab=this->gabinetes.begin();this->itGab!=this->gabinetes.end();++itGab)
	{
		//output dos elementos relevantes atraves do iterador.
		//(*itProf) permite acesso ao objecto
		cout <<setfill(' ')  << setw(11)<<left << "*";
		cout << setw(11) <<  (*itGab)->getCodigoSala()<< setw(20)<<left << "*";
		cout << setw(22)<<  (*itGab)->getNumSecretarias()<< setw(15)<<left<<"*";
        if((*itGab)->getAdministrativo() == 1)
		{
            cout << setw(17) <<  "Sim" << setw(4)<<left << "*";
            cout << setw(15) << "----" << "*"<< endl;
        }else
        {
            cout << setw(17) <<  "Nao" << setw(4)<<left << "*";
            cout << setw(15) << (*itGab)->getDepartamento().getNome() << "*"<< endl;
        }

	}
	cout<<setfill('*')<<setw(116)<<"*"<<endl;

}

//Criação de novo Administrativo com recurso a ponteiro para Administrativo.
void Universidade::novoAdministrativo()
{
	Administrativo* nAdmin = new Administrativo();
	nAdmin->inserirDados();
	administrativos.push_back(nAdmin);
}

//Inserção automatica de elementos no vetor Administrativo.
void Universidade::novoAdministrativo(int numFuncionario,string nome,int numID,string morada,int anosServico)
{
	Administrativo* nAdmin = new Administrativo(numFuncionario,nome,numID,morada,anosServico);
	administrativos.push_back(nAdmin);
}

//Listagem completa do vetor Administrativos
void Universidade::listaAdministrativos()
{
	cout<<setfill('*')<<setw(100)<<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(37)<< " " << setw(25) << "Listagem geral Administrativos" << setfill(' ')<<setw(32) << "*" << endl;
	cout <<setfill('*')<<setw(100)<<"*"<<endl;
	cout << setfill(' ') << "*";
    cout << setw(10) << "ID Func" << setw(2)<< "*";
	cout << setw(21) << "Nome" << setw(18)<< right<< "*";
	cout << setw(6)<< "ID"<< setw(5)<< right<< "*";
	cout << setw(14) << "Morada" << setw(10)<< right<< "*";
	cout << setw(9) << "Salario" << setw(4)<< right<< "*"<< endl;
	cout<<setfill('*')<<setw(100)<<"*"<<endl;
	for(itAdmin=administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
	{
		cout <<setfill(' ')  << setw(6)<<left << "*";
		cout << setw(6) <<  (*itAdmin)->getNumFuncionario()<< setw(13)<<left << "*";
		cout << setw(26)<<  (*itAdmin)->getNome()<< setw(3)<<left<<"*";
		cout << setw(8) <<  (*itAdmin)->getNumIdentificao() << setw(5)<<left << "*";
		cout << setw(19) <<  (*itAdmin)->getMorada()<< setw(3)<<left << "*";
		cout << setw(10) << (*itAdmin)->getSalario() << "*"<< endl;
	}
	cout<<setfill('*')<<setw(100)<<"*"<<endl;
}

//Metodo para output do salario de Administrativos com recurso a um ponteiro para Funcionario
//Força a utilização do polimorfismo existente na relação entre classes
float Universidade::salarioAdmin()
{
	float salario=0.0;
	for(itAdmin = administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
	{
		Funcionario *admin = (*itAdmin);
		salario+=admin->getSalario();
	}
	return salario;
}

//Remoção de professores
void Universidade::apagaProfessor(int &id)
{
	for(itProf=professores.begin();itProf!=professores.end();++itProf)
		if((*itProf)->getNumFuncionario()== id)
		{
			//Libertada memoria do elemento
			delete (*itProf);
			//Atualizada & Apagada posição no vetor
			professores.erase(itProf);
			break;
		}
}

//Remoção de Administrativos
void Universidade::apagaAdministrativo(int &id)
{
	for(itAdmin=administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
	{
		if((*itAdmin)->getNumFuncionario()==id)
		{
			//Liberta memoria do elemento & Atualizada & Apagada posição no vetor
			delete (*itAdmin);
			administrativos.erase(itAdmin);
			break;
		}
	}
}


//Calculo do salario total de todos os funcionarios.  Utilização de ponteiros para a classe Funcionario.
//Utilização do polimorfismo existente na classes Funcionario,Professor e Administrativo
float Universidade::salarioTotal()
{
	float total=0;
	for(itAdmin = administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
	{
		Funcionario *admin = (*itAdmin);
		total+=admin->getSalario();
	}
	for(itProf = professores.begin();itProf!=professores.end();++itProf)
	{
		Funcionario *prof = (*itProf);
		total+=prof->getSalario();
	}

	return total;
}

//Calculo do salario de todos os professores
//Utilização do polimorfismo da classe
float Universidade::salarioProfessor()
{
	float total=0;
	for(itProf = professores.begin();itProf!=professores.end();++itProf)
	{
		Funcionario *prof = (*itProf);
		total+=prof->getSalario();
	}
	return total;
}

//metodo para criação do ficheiro com dados de funcionarios
void Universidade::salvarFicheiro()
{
	//Criação da variael utilizando a classe ofstream.
	ofstream mFicheiro;
	//Abertura do ficheiro, com a classe ofstream o ficheiro por defeito é aberto para operacoes de output
	//Caso o ficheiro não exista é criado novo ficheiro.
	mFicheiro.open("Funcionarios.txt");
	/*
	 * Outuput para o ficheiro identica a utilização de cout
	 * Criação de um display visual identico ao estilo utilizado no programa
	 */
    mFicheiro<<setfill('*')<<setw(100)<<"*"<<endl;
	mFicheiro << "*" << setfill(' ')<<setw(37)<< " " << setw(25) << "Listagem geral Administrativos" << setfill(' ')<<setw(32) << "*" << endl;
	mFicheiro <<setfill('*')<<setw(100)<<"*"<<endl;
	mFicheiro << setfill(' ') << "*";
    mFicheiro << setw(10) << "ID Func" << setw(2)<< "*";
	mFicheiro << setw(21) << "Nome" << setw(18)<< right<< "*";
	mFicheiro << setw(6)<< "ID"<< setw(5)<< right<< "*";
	mFicheiro << setw(14) << "Morada" << setw(10)<< right<< "*";
	mFicheiro << setw(9) << "Salario" << setw(4)<< right<< "*"<< endl;
	mFicheiro<<setfill('*')<<setw(100)<<"*"<<endl;
	for(itAdmin=administrativos.begin();itAdmin!=administrativos.end();++itAdmin)
	{
		mFicheiro <<setfill(' ')  << setw(6)<<left << "*";
		mFicheiro << setw(6) <<  (*itAdmin)->getNumFuncionario()<< setw(13)<<left << "*";
		mFicheiro << setw(26)<<  (*itAdmin)->getNome()<< setw(3)<<left<<"*";
		mFicheiro << setw(8) <<  (*itAdmin)->getNumIdentificao() << setw(5)<<left << "*";
		mFicheiro << setw(19) <<  (*itAdmin)->getMorada()<< setw(3)<<left << "*";
		mFicheiro << setw(10) << (*itAdmin)->getSalario() << "*"<< endl;
	}
	mFicheiro<<setfill('*')<<setw(100)<<"*"<<endl;

    mFicheiro << endl;
    mFicheiro << endl;

    mFicheiro<<setfill('*')<<setw(116)<<"*"<<endl;
	mFicheiro << "*" << setfill(' ')<<setw(37)<< " " << setw(26) << "Listagem geral Professores" << setfill(' ')<<setw(52) << "*" << endl;
	mFicheiro <<setfill('*')<<setw(116)<<"*"<<endl;
	mFicheiro << setfill(' ') << "*";
    mFicheiro << setw(10) << "ID Func" << setw(2)<< "*";
	mFicheiro << setw(19) << "Nome" << setw(16)<< right<< "*";
	mFicheiro << setw(6)<< "ID"<< setw(5)<< right<< "*";
	mFicheiro << setw(14) << "Morada" << setw(10)<< right<< "*";
	mFicheiro << setw(14) << "Departamento" << setw(3)<< right<< "*";
    mFicheiro << setw(11) << "Categoria" << setw(5)<< right<< "*"<< endl;
	mFicheiro<<setfill('*')<<setw(116)<<"*"<<endl;
	for(this->itProf=this->professores.begin();this->itProf!=this->professores.end();++itProf)
	{
		mFicheiro <<setfill(' ')  << setw(6)<<left << "*";
		mFicheiro << setw(6) <<  (*itProf)->getNumFuncionario()<< setw(13)<<left << "*";
		mFicheiro << setw(22)<<  (*itProf)->getNome()<< setw(3)<<left<<"*";
		mFicheiro << setw(8) <<  (*itProf)->getNumIdentificao() << setw(5)<<left << "*";
		mFicheiro << setw(19) <<  (*itProf)->getMorada()<< setw(4)<<left << "*";
		mFicheiro << setw(13) << (*itProf)->getDepartamento().getNome() <<setw(3)<<left << "*";
        mFicheiro << setw(13) << (*itProf)->getCategoriaString() << "*"<< endl;
	}
	mFicheiro<<setfill('*')<<setw(116)<<"*"<<endl;
}


//Remoção de departamentos
void Universidade::apagaDepartamento(int &id)
{
	for(itDpt=departamentos.begin();itDpt!=departamentos.end();++itDpt)
	{
		if((itDpt-departamentos.begin()) == (id-1))
		{
			//Liberta memoria do elemento & Atualizada & Apagada posição no vetor
			delete (*itDpt);
			departamentos.erase(itDpt);
			break;
		}
	}
}

//Listagem de Professores, conforme o departamento selecionado
void Universidade::listaProfDpt(int &id)
{
    cout<<setfill('*')<<setw(100)<<"*"<<endl;
	cout << "*" << setfill(' ')<<setw(37)<< " " << setw(26) << "Listagem geral Professores" << setfill(' ')<<setw(36) << "*" << endl;
	cout <<setfill('*')<<setw(100)<<"*"<<endl;
	cout << setfill(' ') << "*";
    cout << setw(10) << "ID Func" << setw(2)<< "*";
	cout << setw(19) << "Nome" << setw(16)<< right<< "*";
	cout << setw(6)<< "ID"<< setw(5)<< right<< "*";
	cout << setw(14) << "Morada" << setw(10)<< right<< "*";
	cout << setw(14) << "Departamento" << setw(3)<< right<< "*"<< endl;
	cout<<setfill('*')<<setw(100)<<"*"<<endl;

	//Precorre o vetor de departamentos para encontrar o departamento selecionado, evita que a seleção errada
	//de um departamento crie um erro ao pesquisar no vetor de professores
	for(itDpt=departamentos.begin();itDpt!=departamentos.end();++itDpt)
	{
		if((itDpt-departamentos.begin()) == (id-1))
		{
			//Quando encontrado o departamento em questão, precorre o vetor de professores
			//e faz output de todos os professores existentes no departamento em questão
			for(itProf=professores.begin();itProf!=professores.end();++itProf)
			{
				if((*itProf)->getDepartamento().getNome() == (*itDpt)->getNome())
				{
					cout <<setfill(' ')  << setw(6)<<left << "*";
					cout << setw(6) <<  (*itProf)->getNumFuncionario()<< setw(13)<<left << "*";
					cout << setw(22)<<  (*itProf)->getNome()<< setw(3)<<left<<"*";
					cout << setw(8) <<  (*itProf)->getNumIdentificao() << setw(5)<<left << "*";
					cout << setw(19) <<  (*itProf)->getMorada()<< setw(4)<<left << "*";
					cout << setw(13) << (*itProf)->getDepartamento().getNome() << "*"<< endl;
				}

			}
		}
	}
	cout<<setfill('*')<<setw(100)<<"*"<<endl;
}



//Remoção de gabinetes
void Universidade::apagaGabinete(int &id)
{
	for(itGab=gabinetes.begin();itGab!=gabinetes.end();++itGab)
	{
		if((*itGab)->getCodigoSala()==id)
		{
			//Liberta memoria do elemento & Atualizada & Apagada posição no vetor
			delete (*itGab);
			gabinetes.erase(itGab);
			break;
		}
	}
}

//Remoção de salaAulas
void Universidade::apagaSala(int &id)
{
	for(itSL=salasAulas.begin();itSL!=salasAulas.end();++itSL)
	{
		if((*itSL)->getCodigoSala()==id)
		{
			//Liberta memoria do elemento & Atualizada & Apagada posição no vetor
			delete (*itSL);
			salasAulas.erase(itSL);
			break;
		}
	}
}
