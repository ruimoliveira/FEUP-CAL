/*
 * Facility.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Facility.h"

Facility::Facility() {}

Facility::Facility(int id, string type, Node position, vector<Vehicle> vehicles): id(id), type(type), position(position), vehicles(vehicles){}

Facility::~Facility() {}

int Facility::getId() const {
	return id;
}

vector<Vehicle> Facility::getVehicles(){
	return this->vehicles;
}

const Node& Facility::getPosition() const {
	return position;
}

const string& Facility::getType() const {
	return type;
}
