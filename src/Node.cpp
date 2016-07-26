/*
 * Node.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: fox
 */

#include "Node.h"

using namespace std;

Node::Node(int id) {
	this->id = id;
	this->ifTrue = NULL;
	this->ifFalse = NULL;
	this->combatant = NULL;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

void Node::setCombatant(Combatant *combatant) {
	this->combatant = combatant;
}

Combatant * Node::getCombatant() {
	return this->combatant;
}

Node* Node::execute() {
	if (this->eval()) {
		return this->ifTrue;
	} else {
		return this->ifFalse;
	}
}

void Node::setTrue(Node *node) {
	this->ifTrue = node;
}

void Node::setFalse(Node *node) {
	this->ifFalse = node;
}

bool Node::eval() {
	cout << "## DEFAULT" << endl;
	return true;
}
