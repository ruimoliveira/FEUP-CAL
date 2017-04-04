/*
 * Road.h
 */
#ifndef ROAD_H_
#define ROAD_H_

#include <vector>
#include <queue>
#include "Node.h"
using namespace std;

class Road {
	long long id;
	string name;
	bool twoWay;
public:
	Road(long long id, string name, bool twoWay);
	~Road();
	void printInfo();
};

#endif /* ROAD_H_ */
