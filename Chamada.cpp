/*
 * Chamada.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Chamada.h"

Chamada::Chamada() {
	// TODO Auto-generated constructor stub

}

Chamada::~Chamada() {
	// TODO Auto-generated destructor stub
}

Chamada::Chamada(Posicao localidade, unsigned int grauUrgencia, string motivo){
	this->localidade = localidade;
	this->grauUrgencia = grauUrgencia;
	this->motivo = motivo;
}

Posicao Chamada::getLocalidade(){
	return this->localidade;
}

unsigned int Chamada::getGrauUrgencia(){
	return this->grauUrgencia;
}

string Chamada::getMotivo(){
	return this->motivo;
}
