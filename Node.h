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
	Node(long long id);
	~Node(){};
	void printInfo();
	long long getId() const;
	double getxDeg() const;
	double getxRad() const;
	double getyDeg() const;
	double getyRad() const;
	bool operator == (const Node & p2) const;

};

#endif /* NODE_H_ */
