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
	this->clip = 2;
}

Blue::~Blue() {
	// TODO Auto-generated destructor stub
}

void Blue::initialise() {
	RangeNode *node1 = new RangeNode(1, -5, 5);
	RangeNode *node2 = new RangeNode(2, 0, 180);
	TurnNode *node3 = new TurnNode(3, 1);
	TurnNode *node4 = new TurnNode(4, -1);
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

