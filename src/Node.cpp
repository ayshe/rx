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

void Node::execute() {
	cout << "Exec node" + to_string(this->id) << endl;
	if (false) {
		cout << "Case TRUE ... ";
		if (NULL != this->ifTrue) {
			ifTrue->execute();
		} else {
			cout << "End program";
		}
	} else {
		cout << "Case FALSE ... " << endl;
		if (NULL != this->ifFalse) {
			ifFalse->execute();
		} else {
			cout << "End program" << endl;
		}
	}
	cout << endl;
}

void Node::setTrue(Node *node) {
	this->ifTrue = node;
}

void Node::setFalse(Node *node) {
	this->ifFalse = node;
}
