/*
 * Runner.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */
#include <stddef.h>
#include <iostream>
#include <string>
#include <tgmath.h>

#include "Runner.h"
#include "../Acp.h"

using namespace std;

Runner::Runner() : node() {
	// TODO Auto-generated constructor stub
	this->acpCount = 0;
	this->executions = 0;
}

Runner::~Runner() {
	// TODO Auto-generated destructor stub
}

void Runner::registerAcp(Acp *acp) {
	if (this->acpCount > MAX_ACP_COUNT) {
		return;
	}
	this->acp[this->acpCount] = acp;
	this->acpCount++;
}

void Runner::run() {
	while (this->executions < MAX_EXECUTIONS) {
		this->calculatePositions();
		for (int i=0; i<this->acpCount; i++) {
			this->executions ++;
			Node *toExecute = this->node[i];
			if (toExecute == NULL) {
				toExecute = this->acp[i]->getEntrypoint();
			}
			if (toExecute != NULL) {
				this->node[i] = toExecute->execute();
			}
		}
	}
}

void Runner::calculatePositions() {
	for (int i=0; i<this->acpCount; i++) {
		Acp *thisACP = this->acp[i];
		this->acp[i]->clearTargets();
		for (int t=0; t<this->acpCount; t++) {
			if (t != i) {
				Acp *thatACP = this->acp[t];
				float bearing = (atan2(thisACP->getY() - thatACP->getY(), thisACP->getX() - thatACP->getX())) * 180 / M_PI;
				float range = sqrt((thatACP->getX() - thisACP->getX())*(thatACP->getX() - thisACP->getX()) + (thatACP->getY() - thisACP->getY())*(thatACP->getY()- thisACP->getY()));
				this->acp[i]->addTarget(new Target(t, bearing, range));
				//cout << "Target ACP" + to_string(t) + " bearing " + to_string(bearing) + " range " + to_string(range) << endl;
			}
		}
		this->acp[i]->setPrimaryTarget();
	}
}
