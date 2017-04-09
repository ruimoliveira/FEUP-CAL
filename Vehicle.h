/*
 * Vehicle.h
 *
 *  Created on: 21/03/2017
 *      Author: up201406136
 */

#include <string>
#include "Node.h"

#ifndef VEHICLE_H_
#define VEHICLE_H_

using namespace std;

/**
 * Vehicle Class. Abstract representation of a vehicle owned by a facility.
 */
class Vehicle {
	int id;
	string type;
	bool available;
	Node * position;
public:
	/**
	 * @brief Vehicle default constructor. Has no parameters.
	 */
	Vehicle();

	/**
	 * @brief Vehicle constructor, which takes three parameters.
	 * @param id
	 * Vehicle id.
	 * @param type
	 * Vehicle type should be set to MOTORCYCLE, PATROLCAR, AMBULANCE, FIREENGINE, FIRETRUCK.
	 * @param position
	 * Node where the vehicle is located.
	 */
	Vehicle(int id, string type, Node * position);

	/**
	 * @brief Vehicle default deconstructor.
	 */
	~Vehicle();

	/**
	 * @brief Returns the ID of the Vehicle.
	 */
	int getId() const;

	/**
	 * @brief Returns wether vehicle is available or not.
	 */
	bool isAvailable() const;

	/**
	 * @brief Sets wether vehicle is available or not.
	 */
	void setAvailable(bool available);

	/**
	 * @brief Gets the position of the Vehicle.
	 */
	const Node* getPosition() const;

	/**
	 * @brief Sets the position of the Vehicle.
	 */
	void setPosition(Node* position);

	/**
	 * @brief Gets the type of the Vehicle.
	 */
	const string& getType() const;
};

#endif /* VEHICLE_H_ */
