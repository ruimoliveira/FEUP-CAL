/*
 * Vehicle.cpp
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(int id, string type, Node * position): id(id), type(type), position(position){
	this->available = true;
}

Vehicle::~Vehicle() {}

bool Vehicle::isAvailable() const {
	return available;
}

void Vehicle::setAvailable(bool available) {
	this->available = available;
}

const Node* Vehicle::getPosition() const {
	return position;
}

void Vehicle::setPosition(Node* position) {
	this->position = position;
}

const string& Vehicle::getType() const {
	return type;
}

int Vehicle::getId() const {
	return id;
}
