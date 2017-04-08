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

Chamada::Chamada(Node posicao, string motivo){
	this->posicao = posicao;
	//this->grauUrgencia = grauUrgencia;
	this->motivo = motivo;
}

Node Chamada::getPosicao(){
	return this->posicao;
}

/*unsigned int Chamada::getGrauUrgencia(){
	return this->grauUrgencia;
}*/

string Chamada::getMotivo(){
	return this->motivo;
}

void Chamada::setPosicao(Node posicao){
	this->posicao = posicao;
}

/*void Chamada::setGrauUrgencia(unsigned int grauUrgencia){
	this->grauUrgencia = grauUrgencia;
}*/

void Chamada::setMotivo(string motivo){
	this->motivo = motivo;
}
