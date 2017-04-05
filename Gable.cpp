#include "Gable.h"

using namespace std;

Gable::Gable(long long roadID, long long startID, long long finishID) :
		roadID(roadID), startID(startID), finishID(finishID) {
}

long long Gable::getFinishId() const {
	return finishID;
}

long long Gable::getRoadId() const {
	return roadID;
}

long long Gable::getStartId() const {
	return startID;
}

void Gable::printInfo() {
	cout << "Gable: roadID (" << this->roadID << ") - startID(" << this->startID
			<< ") - finishID(" << this->finishID << ")" << endl;
}
