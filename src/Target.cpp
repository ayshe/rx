/*
 * Target.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#include "Target.h"

Target::Target(int id, float bearing, float range) {
	// TODO Auto-generated constructor stub
	this->id = id;
	this->bearing = bearing;
	this->range = range;
}

Target::~Target() {
	// TODO Auto-generated destructor stub
}

int Target::getId() {
	return this->id;
}

void Target::setId(int id) {
	this->id = id;
}

float Target::getBearing() {
	return this->bearing;
}

void Target::setBearing(float bearing) {
	this->bearing = bearing;
}

float Target::getRange() {
	return this->range;
}

void Target::setRange(float range) {
	this->range = range;
}
