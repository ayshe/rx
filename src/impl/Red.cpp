/*
 * Red.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#include "Red.h"

Red::Red(int id) : Acp(id) {
	// TODO Auto-generated constructor stub
	this->initialise();
	this->clip = 1;
}

Red::~Red() {
	// TODO Auto-generated destructor stub
}

void Red::initialise() {
	RangeNode *node1 = new RangeNode(1, -30, 30);
	RangeNode *node2 = new RangeNode(2, 0, 180);
	TurnNode *node3 = new TurnNode(3, 2);
	TurnNode *node4 = new TurnNode(4, -2);

	node1->setFalse(node2);

	node2->setTrue(node3);
	node2->setFalse(node4);

	this->addNode(node1);
	this->addNode(node2);
	this->addNode(node3);
	this->addNode(node4);
}
