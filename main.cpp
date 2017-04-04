
#include <iostream>
#include <fstream>
#include <sstream>

#include "Graph.h"
#include "Node.h"
#include "Gable.h"
#include "Road.h"

using namespace std;


Graph<Node, Road> map;


vector<Node *> loadNodes(){
	ifstream file;
	string filename;
	vector<Node *> crossroads;

	filename = "A.txt";

	file.open(filename.c_str(),ifstream::in);

	char sep;

	string line;
	long long id;
	double xDeg, yDeg, xRad, yRad;

	while( !file.eof() ){

		getline(file, line);
		if(line == "") continue;

		stringstream ss;
		ss.str(line);
		//cout << line << endl;
		ss >> id >> sep;
		ss >> xDeg >> sep;
		ss >> yDeg >> sep;
		ss >> xRad >> sep;
		ss >> yRad >> sep;

		//cout << id << ";" << xDeg << ";" << yDeg << ";" << xRad << ";" << yRad << endl;

		Node* node = new Node(id, xDeg, yDeg, xRad, yRad);
		crossroads.push_back(node);
	}

	file.close();

	/*
	for(unsigned int i=0; i<crossroads.size(); i++){
		cout << i << endl;
		crossroads[i]->printInfo();
	}
	*/

	return crossroads;
}

vector<Road *> loadRoads(){
	ifstream file;
	string filename;
	vector<Road *> roads;

	filename = "B.txt";

	file.open(filename.c_str(),ifstream::in);

	char sep;

	string line, name, boolean;
	long long id;
	bool twoWay;

	while( !file.eof() ){

		getline(file, line);
		if(line == "") continue;

		stringstream ss;
		ss.str(line);
		//cout << line << endl;
		ss >> id >> sep;

		line = line.substr(line.find(";")+1, string::npos);
		name = line.substr(0, line.find(";"));

		line = line.substr(line.find(";")+1, string::npos);
		boolean = line.substr(0, line.find("\n"));

		if (boolean[0] == 'T') {
			twoWay = true;
		} else if(boolean[0] == 'F') {
			twoWay = false;
		}

		//cout << id << ";" << name << ";" << boolean << endl;

		Road* road = new Road(id, name, twoWay);
		roads.push_back(road);
	}

	file.close();

/*
	for(unsigned int i=0; i<roads.size(); i++){
		cout << i << endl;
		roads[i]->printInfo();
	}
*/
	return roads;
}

vector<Gable *> loadConnections(){
	ifstream file;
	string filename;
	vector<Gable *> connections;

	filename = "C.txt";

	file.open(filename.c_str(),ifstream::in);

	char sep;

	string line;
	long long roadID, nodeID1, nodeID2;

	while( !file.eof() ){

		getline(file, line);
		if(line == "") continue;

		stringstream ss;
		ss.str(line);
		//cout << line << endl;
		ss >> roadID >> sep;
		ss >> nodeID1 >> sep;
		ss >> nodeID2 >> sep;

		//cout << roadID << ";" << nodeID1 << ";" << nodeID2 << endl;

		Gable* gable = new Gable(roadID, nodeID1, nodeID2);
		connections.push_back(gable);
	}

	file.close();

/*
	for(unsigned int i=0; i<connections.size(); i++){
		cout << i << endl;
		connections[i]->printInfo();
	}
*/

	return connections;
}

void loadMap(Graph<Node, Road> & map){
	loadNodes();
	loadRoads();
	loadConnections();

	map.
}

int main() {
	cout << "PRINT MENU" << endl;

	loadMap(map);


	return 0;
}
