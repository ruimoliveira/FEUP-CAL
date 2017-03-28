/*
 * Chamada.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>

#include "Posicao.h"

using namespace std;

#ifndef CHAMADA_H_
#define CHAMADA_H_

class Chamada {
private:
	Posicao localidade;
	unsigned int grauUrgencia;
	string motivo;
public:
	Chamada();
	virtual ~Chamada();
	Chamada(Posicao localidade, unsigned int grauUrgencia, string motivo);
	Posicao getLocalidade();
	unsigned int getGrauUrgencia();
	string getMotivo();
	void setLocalidade(Posicao localidade);
	void setGrauUrgencia(unsigned int grauUrgencia);
	void setMotivo(string motivo);
};

#endif /* CHAMADA_H_ */
