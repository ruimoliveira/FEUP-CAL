
#include "Urgencies.h"

Urgencies::Urgencies(){

}

Urgencies::Urgencies(Graph<Node, Road> * map): map(map){}

Graph<Node, Road> * Urgencies::getMap(){
	return this->map;
}

double Urgencies::getPathDistance(Node startNode, Node finishNode){
	map->getPath(startNode, finishNode);
}

Node Urgencies::getNode(long long nodeId){
	typename vector<Vertex<Node, Road> *>::iterator it_graph = map->getVertexSet().begin();
	typename vector<Vertex<Node, Road> *>::iterator ite_graph = map->getVertexSet().end();

	for (; it_graph != ite_graph; it_graph++) {
		if((*it_graph)->getInfo().getId() == nodeId){
			return (*it_graph)->getInfo();
		}
	}

	return Node(-1);
}
