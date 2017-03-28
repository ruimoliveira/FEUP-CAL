/*
 * Policia.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#ifndef POLICIA_H_
#define POLICIA_H_

using namespace std;

class Policia {
private:
	Posicao posicao;
	Veiculo veiculo;
public:
	Policia();
	virtual ~Policia();
	Policia(Posicao posicao, Veiculo veiculo);
	Posicao getPosicao();
	Veiculo getVeiculo();
	void setPosicao(Posicao posicao);
	void setVeiculo(Veiculo veiculo);
};

#endif /* POLICIA_H_ */
