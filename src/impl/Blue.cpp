/*
 * Blue.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */
#include <iostream>

#include "Blue.h"

using namespace std;

Blue::Blue(int id) : Acp(id) {
	// TODO Auto-generated constructor stub
	this->initialise();
}

Blue::~Blue() {
	// TODO Auto-generated destructor stub
}

void Blue::initialise() {
	RangeNode *node1 = new RangeNode(1, -30, 30);
	RangeNode *node2 = new RangeNode(2, 0, 180);
	TurnNode *node3 = new TurnNode(3, 10);
	TurnNode *node4 = new TurnNode(4, -10);
	FireNode *node5 = new FireNode(5);

	node1->setTrue(node5);
	node1->setFalse(node2);

	node2->setTrue(node3);
	node2->setFalse(node4);

	this->addNode(node1);
	this->addNode(node2);
	this->addNode(node3);
	this->addNode(node4);
	this->addNode(node5);
}

