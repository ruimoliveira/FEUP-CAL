#include "Road.h"

Road::Road(unsigned long long id, string name, bool twoWay): id(id), name(name), twoWay(twoWay){}

Road::Road(unsigned long long id): id(id){}

unsigned long long Road::getId() const {
	return id;
}

const string& Road::getName() const {
	return name;
}

bool Road::isTwoWay() const {
	return twoWay;
}

void Road::printInfo(){
	cout << "Node: id (" << this->id << ") - name(" << this->name << ") - twoWay("
			<< this->twoWay << ")" << endl;
}

bool Road::operator == (const Road & p2) const{
	return this->id==p2.id;
}
