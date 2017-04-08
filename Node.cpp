/*
 * Node.h
 */
#include "Node.h"

using namespace std;

Node::Node(){

}

Node::Node(long long id, double xDeg, double yDeg, double xRad, double yRad) :
		id(id), xDeg(xDeg), yDeg(yDeg), xRad(xRad), yRad(yRad) {
}

Node::Node(long long id): id(id){}

long long Node::getId() const {
	return id;
}

double Node::getxDeg() const {
	return xDeg;
}

double Node::getxRad() const {
	return xRad;
}

double Node::getyDeg() const {
	return yDeg;
}

double Node::getyRad() const {
	return yRad;
}

void Node::printInfo() {
	cout << "Node: id (" << this->id << ") - xDeg(" << this->xDeg << ") - yDeg("
			<< this->yDeg << ") - xRad(" << this->xRad << ") - yRad("
			<< this->yRad << ")" << endl;
}

bool Node::operator == (const Node & p2) const{
	return this->id == p2.id;
}
