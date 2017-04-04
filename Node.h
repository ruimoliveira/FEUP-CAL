/*
 * Node.h
 */
#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include <queue>
#include <iostream>

class Node {
private:
	long long id;
	double xDeg, yDeg, xRad, yRad;
public:
	Node(long long id, double xDeg, double yDeg, double xRad, double yRad);
	~Node();
	void printInfo();
};

#endif /* NODE_H_ */
