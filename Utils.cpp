#include "Utils.h"

vector<Node> Utils::loadNodes(){
	ifstream file;
	string filename;
	vector<Node> crossroads;

	filename = "A.txt";

	file.open(filename.c_str(),ifstream::in);

	char sep;

	string line;
	unsigned long long id;
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
	unsigned long long id;
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
	unsigned long long roadID, nodeID1, nodeID2;

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

vector<Facility> Utils::loadFacilities(){
	vector<Facility> facilities;
	for(unsigned int z=0; z<3; z++){
		ifstream file;
		string filename;

		string type;
		switch(z){
		case 0:
			filename = "Hospitals.txt";
			type = "HOSPITAL";
			break;
		case 1:
			filename = "FireStations.txt";
			type = "FIRESTATION";
			break;
		case 2:
			filename = "PoliceStations.txt";
			type = "POLICESTATION";
			break;
		}

		file.open(filename.c_str(),ifstream::in);

		char sep;

		string line, aux, vehicleType;
		int vehicleID, facilityID;
		vector<Vehicle> vehicles;
		Node *vehiclePosition, *facilityPosition;
		unsigned long long position;

		while( !file.eof() ){
			stringstream ss;
			getline(file, line);
			if(line == "") continue;

			aux = line.substr(0, line.find(";"));
			line = line.substr(line.find(";")+1, string::npos);

			if(aux.compare("hspt") == 0 || aux.compare("ps") == 0 || aux.compare("fs") == 0){
				aux = line.substr(0, line.find(";"));
				facilityID = atoi(aux.c_str());
				line = line.substr(line.find(";")+1, string::npos);
				ss.str(line);
				ss >> position >> sep;

			} else if (aux.compare("next") == 0) {
				Facility * facility;
				for(unsigned int i=0; i<this->nodes.size(); i++){
					if(nodes[i].getId() == position){
						facilityPosition = &nodes[i];
						facility = new Facility(facilityID, type, facilityPosition);
						break;
					}
				}
				facility->setVehicles(vehicles);
				facilities.push_back(*facility);
				while(vehicles.size() != 0)
					vehicles.erase(vehicles.begin());

		        ss.clear();
		        ss.str("");
			} else {
				vehicleID = atoi(aux.c_str());
				//line = line.substr(line.find(";")+1, string::npos);
				vehicleType = line.substr(0, line.find(";"));
				line = line.substr(line.find(";")+1, string::npos);
				ss.str(line);
				ss >> position >> sep;

				for(unsigned int i=0; i<this->nodes.size(); i++){
					if(nodes[i].getId() == position){
						vehiclePosition = &nodes[i];
						Vehicle vehicle = Vehicle(vehicleID, vehicleType, vehiclePosition);
						vehicles.push_back(vehicle);
						break;
					}
				}
			}

			//cout << roadID << ";" << nodeID1 << ";" << nodeID2 << endl;

		}
	}

	return facilities;
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
	this->facilities = loadFacilities();

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

Node Utils::getNode(unsigned long long nodeId){
	Graph<Node, Road> * map = loadMap();
	typename vector<Vertex<Node, Road> *>::iterator it_graph = map->getVertexSet().begin();
	typename vector<Vertex<Node, Road> *>::iterator ite_graph = map->getVertexSet().end();

	for (; it_graph != ite_graph; it_graph++) {
		if((*it_graph)->getInfo().getId() == nodeId){
			return (*it_graph)->getInfo();
		}
	}

	return Node(-1);
}

unsigned long long Utils::getEdgeID(unsigned long long startId, unsigned long long finishId){
	Graph<Node, Road> * map = loadMap();
	Node start = getNode(startId);

	if (start.getId() == -1){
		return -1;
	}

	typename vector<Edge<Node, Road> >::iterator it_edges = map->getVertex(start)->getAdj().begin();
	typename vector<Edge<Node, Road> >::iterator ite_edges = map->getVertex(start)->getAdj().end();

	for (; it_edges != ite_edges; it_edges++) {
		if((it_edges->getDest()->getInfo().getId() == finishId)){
			return it_edges->getInfo().getId();
		}
	}

	return -1;
}


//nodeDistance

double Utils::calculaDistanciaVetorVertex(vector<Vertex<Node, Road> *> v){

	double res=0;

	for(unsigned int i=0; i<v.size()-1; i++){
		Vertex<Node,Road>* a = v[i];
		Vertex<Node,Road> * b = v[i+1];

		res+=nodeDistance(a->getInfo(),b->getInfo());

	}
	return res;
}


void Utils::displayGraph(){
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(1600, 900);
	gv->defineEdgeColor(ORANGE);
	gv->defineVertexColor(GRAY);
	gv->defineEdgeCurved(false);

	typename vector<Node>::iterator it_node = nodes.begin();
	typename vector<Node>::iterator ite_node = nodes.end();
	int x, y;
	double minLat = nodes[0].getxDeg(),
		maxLat = nodes[0].getxDeg(),
		minLon = nodes[0].getyDeg(),
		maxLon = nodes[0].getyDeg(),
		lat, lon;
	for (unsigned int i=0; i < nodes.size(); i++) {
		lat = nodes[i].getxDeg();
		lon = nodes[i].getyDeg();

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
		//gv->setVertexLabel(it_node->getId(), ".");
	}

	typename vector<Gable>::iterator it_gable = connections.begin();
	typename vector<Gable>::iterator ite_gable = connections.end();

	unsigned long long auxId = 1;

	for (; it_gable != ite_gable; it_gable++) {

		typename vector<Road>::iterator it_road;
		it_road = find(roads.begin(), roads.end(), Road(it_gable->getRoadId()));

		if (it_road->isTwoWay()){
			gv->addEdge(auxId, it_gable->getStartId(), it_gable->getFinishId(), EdgeType::UNDIRECTED);
			gv->setEdgeThickness(auxId, 5);
		}
		else{
			gv->addEdge(auxId, it_gable->getStartId(), it_gable->getFinishId(), EdgeType::DIRECTED);
			gv->setEdgeThickness(auxId, 5);
		}

		auxId++;
	}

	/* TODO: CHANGE FACILITY NODE COLOURS */
	for(unsigned int i=0; i<this->facilities.size(); i++){
		facilities[i].printInfo();
		if(facilities[i].getType().compare("HOSPITAL") == 0){
			gv->setVertexColor(this->facilities[i].getPosition()->getId(),WHITE);
			gv->setVertexLabel(this->facilities[i].getPosition()->getId(), "HOSPITAL");
		} else if(facilities[i].getType().compare("POLICESTATION") == 0){
			gv->setVertexColor(this->facilities[i].getPosition()->getId(),BLUE);
			gv->setVertexLabel(this->facilities[i].getPosition()->getId(), "POLICESTATION");
		} else if(facilities[i].getType().compare("FIRESTATION") == 0){
			gv->setVertexColor(this->facilities[i].getPosition()->getId(),RED);
			gv->setVertexLabel(this->facilities[i].getPosition()->getId(), "FIRESTATION");
		}
	}

	gv->setVertexColor(452590809,RED);
	gv->setVertexLabel(452590809, "FIRESTATION");

	gv->rearrange();
}

vector<Vertex<Node, Road> *> Utils::getBestPath(Graph<Node,Road> map, Node start, Node finish, int algorithm){
	switch (algorithm){
	case 1: map.dijkstraShortestPath(start); //mais barato
	break;
	case 2: map.bellmanFordShortestPath(start); //mais rapido
	break;
	}

	vector <Vertex<Node, Road> *> v = map.getPath(start, finish);

	/*for(unsigned int i = 0; i < v.size(); i++){
		if(i == v.size() - 1){
			cout << v[i]->getInfo().getId() << endl;
		}
		cout << v[i]->getInfo().getId() << "->";
	}*/

	return v;
}

void Utils::displayPath(Graph<Node,Road> map, Node start, Node finish, int algorithm){
	GraphViewer *gv = new GraphViewer(600, 600, false);
	gv->createWindow(1600, 900);
	gv->defineEdgeColor(ORANGE);
	gv->defineVertexColor(BLUE);
	gv->defineEdgeCurved(false);


	vector <Vertex<Node, Road> *> v = getBestPath(map, start, finish, algorithm);
	if(v.size() == 1){
		cout << "Nao foi encontrado caminho para o seu destino." << endl;
	}

	typename vector<Node>::iterator it_node = nodes.begin();
	typename vector<Node>::iterator ite_node = nodes.end();
	int x, y;
	double minLat = nodes[0].getxDeg(),
		maxLat = nodes[0].getxDeg(),
		minLon = nodes[0].getyDeg(),
		maxLon = nodes[0].getyDeg(),
		lat, lon;
	for (unsigned int i=0; i < nodes.size(); i++) {
		lat = nodes[i].getxDeg();
		lon = nodes[i].getyDeg();

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

	typename vector<Gable>::iterator it_gable = connections.begin();
	typename vector<Gable>::iterator ite_gable = connections.end();

	long long auxId = 1;

	for (; it_gable != ite_gable; it_gable++) {

		typename vector<Road>::iterator it_road;
		it_road = find(roads.begin(), roads.end(), Road(it_gable->getRoadId()));

		if (it_road->isTwoWay()){
			gv->addEdge(auxId, it_gable->getStartId(), it_gable->getFinishId(), EdgeType::UNDIRECTED);
			gv->setEdgeThickness(auxId, 5);
		}
		else{
			gv->addEdge(auxId, it_gable->getStartId(), it_gable->getFinishId(), EdgeType::DIRECTED);
			gv->setEdgeThickness(auxId, 5);
		}

		auxId++;
	}

	// CHANGE PATH NODES COLOR
	for (unsigned int i = 0; i < v.size(); i++) {
		if(i == 0)
			//gv->setVertexColor(v[i]->getInfo().getId(), RED);
			gv->setVertexColor(start.getId(), RED);
		else if(i == v.size()-1)
			gv->setVertexColor(v[i]->getInfo().getId(), GREEN);
		else  gv->setVertexColor(v[i]->getInfo().getId(), PINK);
	}

	gv->rearrange();
}

void Utils::printGraphInfo(){
	cout << "O seu mapa contem " << nodes.size() << " nodes e " << roads.size() << " arestas." << endl;
	for(unsigned int i = 0; i < connections.size(); i++){
		cout << "Ligacao " << i+1 << ": ID da aresta - " << connections[i].getRoadId() << "  " << "ID do node de partida - " << connections[i].getStartId() << "  " << "ID do node de chegada - " << connections[i].getFinishId() << endl;
	}
}
