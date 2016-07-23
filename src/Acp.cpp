/*
 * Acp.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#include <stddef.h>
#include "Acp.h"

//Autonomous Combat Platform

Acp::Acp() {
	// Super must be called
	nodeCount = 0;
	entrypoint = NULL;
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
