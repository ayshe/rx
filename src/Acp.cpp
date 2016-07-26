/*
 * Acp.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stddef.h>
#include "Acp.h"

using namespace std;

//Autonomous Combat Platform

Acp::Acp(int id) {
	// Super must be called
	this->nodeCount = 0;
	this->entrypoint = NULL;
	this->id = id;
	cout << "Initialised Combatant " + to_string(id) + " at " + to_string(this->getX()) + ", " + to_string(this->getY()) << endl;

}

Acp::~Acp() {
	// TODO Auto-generated destructor stub
}

void Acp::initialise() {
	// Stub
}

int Acp::getId() {
	return this->id;
}

void Acp::setEntrypoint(Node *node) {
	this->entrypoint = node;
}

void Acp::addNode(Node *node) {
	node->setCombatant(this);
	if (this->nodeCount > MAX_NEXUS_SIZE) {
		return;
	}
	if (this->nodeCount == 0) {
		this->setEntrypoint(node);
	}
	this->nexus[this->nodeCount] = node;
	this->nodeCount++;
}

Node *Acp::getEntrypoint() {
	return this->entrypoint;
}
