/*
 * Posicao.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Posicao.h"

Posicao::Posicao() {
	// TODO Auto-generated constructor stub

}

Posicao::~Posicao() {
	// TODO Auto-generated destructor stub
}

Posicao::Posicao(string nome, int latitude, int longitude){
	this->nome = nome;
	this->latitude = latitude;
	this->longitude = longitude;
}

Posicao::Posicao(int latitude, int longitude){
	this->latitude = latitude;
	this->longitude = longitude;
}

string Posicao::getNome(){
	return this->nome;
}

int Posicao::getLatitude(){
	return this->latitude;
}

int Posicao::getLongitude(){
	return this->longitude;
}

void Posicao::setNome(string nome){
	this->nome = nome;
}

void Posicao::setLatitude(int latitude){
	this->latitude = latitude;
}

void Posicao::setLongitude(int longitude){
	this->longitude = longitude;
}
