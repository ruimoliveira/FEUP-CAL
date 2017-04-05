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
#include "graphviewer.h"
#include "Road.h"
#include "Node.h"
#include "Gable.h"
#include "Graph.h"
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
	void displayGraph(vector< Vertex< Node , Road > > nodes);

};

#endif /* UTILS_H_ */
