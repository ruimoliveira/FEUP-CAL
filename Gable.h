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

class Gable {
	long long roadID, startID, finishID;
public:
	Gable(long long roadID, long long startID, long long finishID);
	~Gable(){};
	void printInfo();
	long long getFinishId() const;
	long long getRoadId() const;
	long long getStartId() const;
};

#endif /* GABLE_H_ */
