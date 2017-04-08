/*
 * Utils.h
 */
#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include "graphviewer.h"
#include "Road.h"
#include "Node.h"
#include "Gable.h"
#include "Graph.h"
#include "Urgencies.h"
using namespace std;

class Utils {
	vector<Node> nodes;
	vector<Road> roads;
	vector<Gable> connections;
	vector<Facility> facilities;
public:
	Utils(){};
	~Utils(){};
	vector<Node> loadNodes();
	vector<Road> loadRoads();
	vector<Gable> loadConnections();
	vector<Facility> loadFacilities();
	double nodeDistance(Node start, Node finish);
	Graph<Node, Road> * loadMap();
	void printMap(Graph<Node, Road> * map);
	void displayGraph();
	vector<Vertex<Node, Road> *> getBestPath(Graph<Node,Road> map, Node start, Node finish, int algorithm);
	void displayPath(Graph<Node,Road> map, Node start, Node finish, int algorithm);
	void printGraphInfo();
	double calculaDistanciaVetorVertex(vector<Vertex<Node, Road> *> v);
	Node getNode(unsigned long long nodeId);
	unsigned long long getEdgeID(unsigned long long startId, unsigned long long finishId);

	vector<Node> getNodes(){return this->nodes;};
	vector<Road> getRoads(){return this->roads;};
	vector<Gable> getConnections(){return this->connections;};
	const vector<Facility>& getFacilities() const {return this->facilities;}

	;
};

#endif /* UTILS_H_ */
