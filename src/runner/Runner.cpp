/*
 * Runner.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */
#include <stddef.h>
#include <iostream>
#include <string>

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
		for (int i=0; i<this->acpCount; i++) {
			this->executions ++;
			Node *toExecute = this->node[i];
			if (toExecute == NULL) {
				toExecute = this->acp[i]->getEntrypoint();
				cout << "ACP " + to_string(i) + " is entrypoint";
				cout << endl;
			} else {

				cout << "ACP " + to_string(i) + " next node ready";
				cout << endl;
			}
			if (toExecute != NULL) {
				cout << "Exec ACP " + to_string(i);
				cout << endl;
				this->node[i] = toExecute->execute();
			}
		}
	}
}
