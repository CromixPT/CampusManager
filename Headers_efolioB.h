//Declaração de metodos usados no main()

#ifndef HEADERS_EFOLIOB_H_
#define HEADERS_EFOLIOB_H_

//Passagem de argumentos entre metodos sempre usando referencias.
estadoMenu processarOpcaoPrincipal(int &opcao);
estadoMenu processarOpcaoMenuPessoal(int &opcao,Universidade& univ);
estadoMenu processarOpcaoMenuDepartamentos(int &opcao,Universidade& univ);
estadoMenu processarOpcaoMenuSalas(int &opcao,Universidade& univ);
void pause();

#endif /* HEADERS_EFOLIOB_H_ */
