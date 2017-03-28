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

Policia::Policia(Posicao posicao, Veiculo veiculo){
	this->posicao = posicao;
	this->veiculo = veiculo;
}

Posicao Policia::getPosicao(){
	return this->posicao;
}

Veiculo Policia::getVeiculo(){
	return this->veiculo;
}

void Policia::setPosicao(Posicao posicao){
	this->posicao = posicao;
}

void Policia::setVeiculo(Veiculo veiculo){
	this->veiculo = veiculo;
}
