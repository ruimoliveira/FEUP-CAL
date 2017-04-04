#include "Road.h"

Road::Road(long long id, string name, bool twoWay): id(id), name(name), twoWay(twoWay){}

void Road::printInfo(){
	cout << "Node: id (" << this->id << ") - name(" << this->name << ") - twoWay("
			<< this->twoWay << ")" << endl;
}
