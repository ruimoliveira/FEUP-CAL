
#include "Urgencies.h"

Urgencies::Urgencies(){

}

Urgencies::Urgencies(Graph<Node, Road> * map): map(map){}

Graph<Node, Road> * Urgencies::getMap(){
	return this->map;
}
