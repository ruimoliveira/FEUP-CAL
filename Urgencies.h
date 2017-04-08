/*
 * Urgencies.h
 */
#ifndef URGENCIES_H_
#define URGENCIES_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "Road.h"
#include "Node.h"
#include "Gable.h"
#include "Graph.h"
using namespace std;

class Urgencies {
	Graph<Node, Road> * map;
public:
	Urgencies();
	~Urgencies(){};
	Urgencies(Graph<Node, Road> * map);
	Graph<Node, Road> * getMap();
};

#endif /* URGENCIES_H_ */
