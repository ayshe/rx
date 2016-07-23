/*
 * Red.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#include "Red.h"

Red::Red() : super() {
	// TODO Auto-generated constructor stub
	this->initialise();
}

Red::~Red() {
	// TODO Auto-generated destructor stub
}

void Red::initialise() {
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);

	node1->setTrue(node3);
	node1->setFalse(node2);

	node2->setTrue(node2);

	node3->setFalse(node3);

	this->addNode(node1);
	this->addNode(node2);
	this->addNode(node3);
}
