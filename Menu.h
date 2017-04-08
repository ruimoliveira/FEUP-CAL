/*
 * Menu.h
 *
 *  Created on: 08/04/2017
 *      Author: Utilizador
 */

#ifndef MENU_H_
#define MENU_H_

#include "Utils.h"
#include <sstream>

#define TAB 			"	"
#define TAB_BIG 		"		"
#define TRIES			3

unsigned short int menuInicial();
unsigned short int menuUrgencias();
unsigned short int menuInformacoes();

void opcoesIniciais(Utils util, Urgencies urgencies);
void opcoesUrgencias(Utils util, Urgencies urgencies);
void opcoesInformacoes(Utils util, Urgencies urgencies);

#endif /* MENU_H_ */
