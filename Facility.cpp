/*
 * Facility.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Facility.h"

Facility::Facility() {}

Facility::Facility(int id, string type, Node * position): id(id), type(type), position(position){}

Facility::~Facility() {}

int Facility::getId() const {
	return id;
}

vector<Vehicle> Facility::getVehicles(){
	return this->vehicles;
}

const string& Facility::getType() const {
	return type;
}

const Node* Facility::getPosition() const {
	return this->position;
}

void Facility::printInfo(){
	cout << "Facility: id (" << this->id << ") - type(" << this->type << ") - position("
			<< this->position->getId() << ") - vehicles:" << endl;
	for(unsigned int i=0; i<this->vehicles.size(); i++){
		cout << "	" << vehicles[i].getId() << "	" << vehicles[i].getType() << endl;
	}
}
