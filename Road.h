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
	Road(){};
	Road(long long id, string name, bool twoWay);
	Road(long long id);
	~Road(){};
	void printInfo();
	long long getId() const;
	const string& getName() const;
	bool isTwoWay() const;
	bool operator == (const Road & p2) const;
};

#endif /* ROAD_H_ */
