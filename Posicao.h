/*
 * Posicao.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>

using namespace std;

#ifndef POSICAO_H_
#define POSICAO_H_

class Posicao {
private:
	string nome;
	int latitude;
	int longitude;
public:
	Posicao();
	virtual ~Posicao();
	Posicao(string nome, int latitude, int longitude);
	Posicao(int latitude, int longitude);
	string getNome();
	int getLatitude();
	int getLongitude();
	void setNome(string nome);
	void setLatitude(int latitude);
	void setLongitude(int longitude);
};

#endif /* POSICAO_H_ */
