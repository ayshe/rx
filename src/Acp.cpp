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

Acp::Acp() {
	// Super must be called
	nodeCount = 0;
	entrypoint = NULL;
	this->hp = 100;
}

Acp::~Acp() {
	// TODO Auto-generated destructor stub
}

void Acp::initialise() {
	// Stub
}

void Acp::setEntrypoint(Node *node) {
	this->entrypoint = node;
}

void Acp::addNode(Node *node) {
	node->setEntity(this);
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
