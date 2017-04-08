/*
 * Facility.h
 *
 *  Created on: 08/04/2017
 *      Author: up201000619
 */

#ifndef FACILITY_H_
#define FACILITY_H_

#include <vector>
#include <string>
#include "Facility.h"
#include "Node.h"
#include "Vehicle.h"

using namespace std;

/**
 * Facility Class. Abstract representation of a hospital, police station and fire station.
 */
class Facility {
	int id;
	string type;
	Node position;
	vector<Vehicle> vehicles;
public:
	/**
	 * @brief Facility default constructor. Has no parameters.
	 */
	Facility();

	/**
	 * @brief Facility default deconstructor.
	 */
	virtual ~Facility();

	/**
	 * @brief Facility constructor, which takes four parameters.
	 * @param id
	 * Facility id.
	 * @param type
	 * Facility type should be set to HOSPITAL, POLICE, FIRESTATION.
	 * @param position
	 * Node where the facility is located.
	 * @param vehicles
	 * Vehicles that operate from this facility.
	 */
	Facility(int id, string type, Node position, vector<Vehicle> police);

	/**
	 * @brief Gets the ID of the Facility.
	 */
	int getId() const;

	/**
	 * @brief Gets the position of the Facility.
	 */
	const Node& getPosition() const;

	/**
	 * @brief Gets the type the Facility.
	 */
	const string& getType() const;

	/**
	 * @brief Gets the vehicles of this Facility.
	 */
	vector<Vehicle> getVehicles();
};

#endif /* FACILITY_H_ */
