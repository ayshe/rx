/*
 * Node.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: fox
 */

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node(int id) {
	this->id = id;
	this->ifTrue = NULL;
	this->ifFalse = NULL;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

Node* Node::execute() {
	Node *next;
	if (this->eval()) {
		return this->ifTrue;
	} else {
		return this->ifFalse;
	}
	return next;
}

void Node::setTrue(Node *node) {
	this->ifTrue = node;
}

void Node::setFalse(Node *node) {
	this->ifFalse = node;
}

bool Node::eval() {
	return true;
}
