/*
 * Node.h
 */
#include "Node.h"

using namespace std;

Node::Node(long long id, double xDeg, double yDeg, double xRad, double yRad) :
		id(id), xDeg(xDeg), yDeg(yDeg), xRad(xRad), yRad(yRad) {
}

void Node::printInfo() {
	cout << "Node: id (" << this->id << ") - xDeg(" << this->xDeg << ") - yDeg("
			<< this->yDeg << ") - xRad(" << this->xRad << ") - yRad("
			<< this->yRad << ")" << endl;
}
