/*
 * Gable.h
 */
#ifndef GABLE_H_
#define GABLE_H_

#include <vector>
#include <queue>
#include "Road.h"
#include "Node.h"
using namespace std;

/**
 * Gable class. Stores the information of a graph connection, with the ID of the two nodes (start and finish) and the ID of the road that connects both of them.
 */
class Gable {
	/** ID of the road that's connecting two nodes. **/
	unsigned long long roadID;

	/** ID of the 1st node the road is connecting. **/
	unsigned long long startID;

	/** ID of the 2nd node the road is connecting. **/
	unsigned long long finishID;
public:
	/**
	 * @brief Gable default constructor. Has no parameters.
	 */
	Gable(){};

	/**
	 * @brief Gable default deconstructor.
	 */
	~Gable(){};

	/**
	 * @brief Gable construtor that gets all the ID's needed.
	 *
	 * @param roadID ID of the road that's connecting two nodes.
	 * @param startID ID of the 1st node that is getting connected.
	 * @param finishID ID of the 2nd node that is getting connected.
	 */
	Gable(unsigned long long roadID, unsigned long long startID, unsigned long long finishID);


	void printInfo();
	unsigned long long getFinishId() const;
	unsigned long long getRoadId() const;
	unsigned long long getStartId() const;
};

#endif /* GABLE_H_ */
