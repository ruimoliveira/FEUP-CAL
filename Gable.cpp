#include "Gable.h"

using namespace std;

Gable::Gable(unsigned long long roadID, unsigned long long startID, unsigned long long finishID) :
		roadID(roadID), startID(startID), finishID(finishID) {
}

unsigned long long Gable::getFinishId() const {
	return finishID;
}

unsigned long long Gable::getRoadId() const {
	return roadID;
}

unsigned long long Gable::getStartId() const {
	return startID;
}

void Gable::printInfo() {
	cout << "Gable: roadID (" << this->roadID << ") - startID(" << this->startID
			<< ") - finishID(" << this->finishID << ")" << endl;
}
