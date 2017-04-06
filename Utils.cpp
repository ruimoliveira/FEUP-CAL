#include "Utils.h"

vector<Node> Utils::loadNodes(){
	ifstream file;
	string filename;
	vector<Node> crossroads;

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

		Node node = Node(id, xDeg, yDeg, xRad, yRad);
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

vector<Road> Utils::loadRoads(){
	ifstream file;
	string filename;
	vector<Road> roads;

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

		Road road = Road(id, name, twoWay);
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

vector<Gable> Utils::loadConnections(){
	ifstream file;
	string filename;
	vector<Gable> connections;

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

		Gable gable = Gable(roadID, nodeID1, nodeID2);
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

/*Code from http://stackoverflow.com/questions/27928/calculate-distance-between-two-latitude-longitude-points-haversine-formula*/
double Utils::nodeDistance(Node start, Node finish){
	int earthRadius = 6371; // Radius of the earth in km
	double dLat = finish.getxRad() - start.getxRad();  // deg2rad below
	double dLon = finish.getyRad() - start.getyRad();
	double a =
		sin(dLat/2) * sin(dLat/2) +
		cos(start.getxRad()) * cos(finish.getxRad()) *
		sin(dLon/2) * sin(dLon/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double d = earthRadius * c; // Distance in km
	return d;
}

Graph<Node, Road> * Utils::loadMap(){
	this->nodes = loadNodes();
	this->roads = loadRoads();
	this->connections = loadConnections();

	Graph<Node, Road> * map = new Graph<Node, Road>();

	for(unsigned int i=0; i<connections.size(); i++){
		typename vector<Node>::iterator nodeStartIt;
		typename vector<Node>::iterator nodeFinishIt;
		typename vector<Road>::iterator roadIt;

		nodeStartIt = find(nodes.begin(), nodes.end(), Node(connections[i].getStartId()));
		nodeFinishIt = find(nodes.begin(), nodes.end(), Node(connections[i].getFinishId()));
		roadIt = find(roads.begin(), roads.end(), Road(connections[i].getRoadId()));

		map->addVertex(*nodeStartIt);
		map->addVertex(*nodeFinishIt);

		if(roadIt->isTwoWay())
			map->addEdge(*nodeFinishIt, *nodeStartIt, nodeDistance(*nodeStartIt, *nodeFinishIt));

		map->addEdge(*nodeStartIt, *nodeFinishIt, nodeDistance(*nodeStartIt, *nodeFinishIt));

	}

	//printMap(map);
	return map;
}

void Utils::printMap(Graph<Node, Road> * map){
	vector<Vertex<Node, Road>*> nodes = map->getVertexSet();
	for (unsigned int i=0; i<nodes.size(); i++) {
		cout << "Node ID: " << nodes[i]->getInfo().getId() << endl;
	}
}


void Utils::displayGraph(vector< Vertex<Node,Road> > nodes){ /*este vector nodes ...*/
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(1600, 900);
	gv->defineEdgeColor(ORANGE);
	gv->defineVertexColor(BLUE);
	gv->defineEdgeCurved(false);

	/*...e' diferente do vector destes iteradores...*/
	typename vector<Node>::iterator it_node = nodes.begin();
	typename vector<Node>::iterator ite_node = nodes.end();
	/*... sim, quando me apercebi tambem ponderei o suicidio.*/
	int x, y;
	double minLat = nodes[0].getInfo().getxDeg(),
		maxLat = nodes[0].getInfo().getxDeg(),
		minLon = nodes[0].getInfo().getxDeg(),
		maxLon = nodes[0].getInfo().getxDeg(),
		lat, lon;
	for (unsigned int i=0; i<nodes.size(); i++) {
		lat = nodes[i].getInfo().getxDeg();
		lon = nodes[i].getInfo().getyDeg();

		if(minLat>lat)
			minLat=lat;
		if(maxLat<lat)
			maxLat=lat;
		if(minLon>lon)
			minLon=lon;
		if(maxLon<lon)
			maxLon=lon;
	}
	for (; it_node != ite_node; it_node++) {
		x = floor(
				((it_node->getyDeg() - minLon) * 1600)
						/ (maxLon - minLon));
		y = floor(
				((it_node->getxDeg() - minLat) * 900)
						/ (maxLat - minLat));

		 gv->addNode(it_node->getId(), x, -y);
	}

}
