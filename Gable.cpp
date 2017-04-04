#include "Gable.h"

using namespace std;

Gable::Gable(long long roadID, long long startID, long long finishID) :
		roadID(roadID), startID(startID), finishID(finishID) {
}

void Gable::printInfo() {
	cout << "Gable: roadID (" << this->roadID << ") - startID(" << this->startID
			<< ") - finishID(" << this->finishID << ")" << endl;
}
