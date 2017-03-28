/*
 * Veiculo.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Veiculo.h"

Veiculo::Veiculo() {
	// TODO Auto-generated constructor stub

}

Veiculo::~Veiculo() {
	// TODO Auto-generated destructor stub
}

Veiculo::Veiculo(string tipo, bool disponibilidade){
	this->tipo = tipo;
	this->disponibilidade = disponibilidade;
}

string Veiculo::getTipo(){
	return this->tipo;
}

bool Veiculo::getDisponibilidade(){
	return this->disponibilidade;
}

Posicao Veiculo::getPosicao(){
	return this->posicao;
}

void Veiculo::setTipo(string tipo){
	this->tipo = tipo;
}

void Veiculo::setDisponibilidade(bool disponibilidade){
	this->disponibilidade = disponibilidade;
}

void Veiculo::setPosicao(Posicao posicao){
	this->posicao = posicao;
}
