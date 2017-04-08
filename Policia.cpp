/*
 * Policia.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Policia.h"

Policia::Policia() {
	// TODO Auto-generated constructor stub

}

Policia::~Policia() {
	// TODO Auto-generated destructor stub
}

Policia::Policia(vector<Veiculo> policia){
	this->policia = policia;
}

vector<Veiculo> Policia::getPolicia(){
	return this->policia;
}

void Policia::setPolicia(vector<Veiculo> policia){
	this->policia = policia;
}
