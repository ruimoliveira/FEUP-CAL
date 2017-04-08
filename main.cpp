#include <vector>
#include "Utils.h"
#include "Urgencies.h"
#include "Menu.h"

using namespace std;

Graph<Node, Road> map;

int main() {
	cout << "PRINT MENU" << endl;

	Utils util = Utils();
	Urgencies nineOneOne = Urgencies(util.loadMap(), util.getFacilities());

	opcoesIniciais(util, nineOneOne);

	return 0;
}
