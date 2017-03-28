/*
 * Veiculo.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>

#ifndef VEICULO_H_
#define VEICULO_H_

using namespace std;

class Veiculo {
private:
	string tipo;
	bool disponibilidade;
	Posicao posicao;
public:
	Veiculo();
	virtual ~Veiculo();
	Veiculo(string tipo, bool disponibilidade);
	string getTipo();
	bool getDisponibilidade();
	Posicao getPosicao();
	void setTipo(string tipo);
	void setDisponibilidade(bool disponibilidade);
	void setPosicao(Posicao posicao);
};

#endif /* VEICULO_H_ */
