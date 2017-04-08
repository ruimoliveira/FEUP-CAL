/*
 * Chamada.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>

#include "Node.h"

using namespace std;

#ifndef CHAMADA_H_
#define CHAMADA_H_

/**
 * Chamada Class. Has as parameters a Node which stores the position the call has been made from and the motive why the call was made.
 */
class Chamada {
private:
	/** Node that stores the position of the call, to where the vehicle needs to go **/
	Node posicao;
	//unsigned int grauUrgencia;
	/** String which stores the motive why the call was made, to determine which service needs to attend to it **/
	string motivo;
public:
	/**
	 * @brief Chamada default constructor. Has no parameters.
	 */
	Chamada();

	/**
	 * @brief Chamada default deconstructor.
	 */
	~Chamada();

	/**
	 * @brief Chamada constructor, which takes two parameters.
	 *
	 * @param posicao Node with the position the call was made from.
	 * @param motivo Motive to why the call was made.
	 */
	Chamada(Node posicao, string motivo);

	/**
	 * @brief Gets the position of the call.
	 */
	Node getPosicao();

	//unsigned int getGrauUrgencia();

	/**
	 * @brief Gets the motive of the call.
	 */
	string getMotivo();

	/**
	 * @brief Sets the position of a call.
	 *
	 * @param posicao New position to be assigned to a call.
	 */
	void setPosicao(Node posicao);

	//void setGrauUrgencia(unsigned int grauUrgencia);

	/**
	 * @brief Sets the motive of a call.
	 *
	 * @param motivo New motive to be assigned to a call.
	 */
	void setMotivo(string motivo);
};

#endif /* CHAMADA_H_ */
