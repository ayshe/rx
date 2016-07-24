/*
 * TurnNode.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#include "TurnNode.h"

using namespace std;

TurnNode::TurnNode(int id, int delta) : Node(id) {
	this->delta = delta;
}

TurnNode::~TurnNode() {
	// TODO Auto-generated destructor stub
}

bool TurnNode::eval() {
	cout << "## TURN" << endl;
	this->entity->turn(this->delta);
	return true;
}

