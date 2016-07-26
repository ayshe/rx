/*
 * rangeNode.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#include "rangeNode.h"

using namespace std;

RangeNode::RangeNode(int id, float from, float to) : Node(id){
	// TODO Auto-generated constructor stub
	this->from = from;
	this->to = to;
}

RangeNode::~RangeNode() {
	// TODO Auto-generated destructor stub
}

bool RangeNode::eval() {
	cout << "## RANGE" << endl;
	return this->combatant->targetInRange(this->from, this->to);
}
