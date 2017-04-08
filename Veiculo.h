/*
 * Veiculo.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>
#include "Node.h"

#ifndef VEICULO_H_
#define VEICULO_H_

using namespace std;

class Veiculo {
private:
	string tipo;
	bool disponibilidade;
	Node posicao;
public:
	Veiculo();
	virtual ~Veiculo();
	Veiculo(string tipo, bool disponibilidade, Node posicao);
	string getTipo();
	bool getDisponibilidade();
	Node getPosicao();
	void setTipo(string tipo);
	void setDisponibilidade(bool disponibilidade);
	void setPosicao(Node posicao);
};

#endif /* VEICULO_H_ */
