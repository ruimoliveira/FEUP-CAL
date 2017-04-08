/*
 * Menu.cpp
 *
 *  Created on: 08/04/2017
 *      Author: Utilizador
 */

#include "Menu.h"

unsigned short int menuInicial()
{
	unsigned short int opcao=-1;
	string temp;
	stringstream aux;
	cout << TAB_BIG << "Menu Inicial";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Menu Urgencias" << endl;
	cout << TAB << "2 - Menu Informacoes" << endl;
	cout << TAB << "0 - Sair do programa" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";
	getline(cin, temp);

	aux << temp;
	aux >> opcao;
	aux.clear();
	aux.str("");

	if(opcao >= 0 && opcao <= 2)
	return opcao;
	else
	return 0;
}

unsigned short int menuUrgencias()
{
	unsigned short int opcao=-1;
	string temp;
	stringstream aux;
	cout << TAB_BIG << "Menu Urgencias";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Enviar INEM a um destino" << endl;
	cout << TAB << "2 - Enviar Policia a um destino" << endl;
	cout << TAB << "3 - Enviar Bombeiros a um destino" << endl;
	cout << TAB << "0 - Voltar" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";
	getline(cin, temp);

	aux << temp;
	aux >> opcao;
	aux.clear();
	aux.str("");

	if(opcao >= 0 && opcao <= 3)
	return opcao;
	else
	return 0;
}

unsigned short int menuInformacoes()
{
	unsigned short int opcao=-1;
	string temp;
	stringstream aux;
	cout << TAB_BIG << "Menu Urgencias";
	cout << endl << endl;
	cout << TAB << "Escolha a opcao que desejar.";
	cout << endl << endl;
	cout << TAB << "1 - Imprimir informacoes sobre o grafo" << endl;
	cout << TAB << "2 - Imprimir informacoes sobre a frota do INEM" << endl;
	cout << TAB << "3 - Imprimir informacoes sobre a frota da Policia" << endl;
	cout << TAB << "4 - Imprimir informacoes sobre a frota dos Bombeiros" << endl;
	cout << TAB << "5 - Ver mapa" << endl;
	cout << TAB << "0 - Voltar" << endl;
	cout << endl;
	cout << "Escreva aqui a sua opcao: ";
	getline(cin, temp);

	aux << temp;
	aux >> opcao;
	aux.clear();
	aux.str("");

	if(opcao >= 0 && opcao <= 5)
	return opcao;
	else
	return 0;
}

void opcoesIniciais(Utils util, Urgencies urgencies)
{
	unsigned short int opcao;

	while((opcao=menuInicial()))
	switch (opcao)
	{
	case 1:opcoesUrgencias(util, urgencies);
	break;
	case 2:opcoesInformacoes(util, urgencies);
	break;
	default:
	opcoesIniciais(util, urgencies);
	break;
	}
}

void opcoesUrgencias(Utils util, Urgencies urgencies)
{
	unsigned short int opcao;

	while((opcao=menuUrgencias()))
	switch (opcao)
	{
	case 1:{
		unsigned int choice1, choice2;
		cin >> choice1;
		cin >> choice2;

		if(choice1 < 0 || choice2 < 0 || choice1 >= util.getNodes().size() || choice2 >= util.getNodes().size()){
			cout << "O node inserido nao existe!" << endl;
		}
		else choice1 >= util.getNodes().size();

		util.displayPath(*urgencies.getMap(), util.getNodes()[choice1], util.getNodes()[choice2], 1);
	}
	break;
	case 2://enviarPolicia();
	break;
	case 3://enviarBombeiros();
	break;
	default:
	opcoesUrgencias(util, urgencies);
	break;
	}
}

void opcoesInformacoes(Utils util, Urgencies urgencies)
{
	unsigned short int opcao;

	while((opcao=menuInformacoes()))
	switch (opcao)
	{
	case 1:util.printGraphInfo();
	break;
	case 2://printINEMInfo();
	break;
	case 3://printPoliciaInfo();
	break;
	case 4://printBombeirosInfo();
	break;
	case 5:util.displayGraph();
	break;
	default:
	opcoesInformacoes(util, urgencies);
	break;
	}
}
