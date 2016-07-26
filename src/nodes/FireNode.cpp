/*
 * FireNode.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: fox
 */

#include "FireNode.h"

#include <iostream>

using namespace std;

FireNode::FireNode(int id) : Node(id) {
	// TODO Auto-generated constructor stub

}

FireNode::~FireNode() {
	// TODO Auto-generated destructor stub
}

bool FireNode::eval() {
	cout << "## FIRE" << endl;
	if (this->combatant != NULL) {
		this->combatant->fireAtPrimaryTarget();
	}
	return true;
}

