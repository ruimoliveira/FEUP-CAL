/*
 * Policia.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#ifndef POLICIA_H_
#define POLICIA_H_

#include "Veiculo.h"
#include <vector>

using namespace std;

class Policia {
private:
	vector<Veiculo> policia;
public:
	Policia();
	virtual ~Policia();
	Policia(vector<Veiculo> policia);
	vector<Veiculo> getPolicia();
	void setPolicia(vector<Veiculo> policia);
};

#endif /* POLICIA_H_ */
