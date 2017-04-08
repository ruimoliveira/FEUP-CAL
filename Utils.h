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
public:
	Utils(){};
	~Utils(){};
	vector<Node> loadNodes();
	vector<Road> loadRoads();
	vector<Gable> loadConnections();
	double nodeDistance(Node start, Node finish);
	Graph<Node, Road> * loadMap();
	void printMap(Graph<Node, Road> * map);
	Node getNode(long long nodeId);
	long long getEdgeID(long long startId, long long finishId);
	void displayGraph();
	vector<Vertex<Node, Road> *> getBestPath(Graph<Node,Road> map, Node start, Node finish, int algorithm);
	void displayPath(Graph<Node,Road> map, Node start, Node finish, int algorithm);
	void printGraphInfo();
	double calculaDistanciaVetorVertex(vector<Vertex<Node, Road> *> v);

	vector<Node> getNodes(){return this->nodes;};
	vector<Road> getRoads(){return this->roads;};
	vector<Gable> getConnections(){return this->connections;};

};

#endif /* UTILS_H_ */
