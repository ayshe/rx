/*
 * Entity.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#include "Entity.h"

#include <iostream>

using namespace std;

Entity::Entity() {
	// TODO Auto-generated constructor stub
	this->clearTargets();
	this->targetCount = 0;
	this->primaryTarget = NULL;
	this->bearing = 0;
	this->x = std::rand() % 100;
	this->y = std::rand() % 100;
	cout << "Initialised Entity at " + to_string(x) + ", " + to_string(y) << endl;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::turn(int delta) {
	this->bearing += delta;
}
void Entity::clearTargets() {
	for (int i=0; i<MAX_ACP_COUNT; i++) {
		delete(this->target[i]);
	}
	this->targetCount = 0;
}

void Entity::addTarget(Target *target) {
	this->target[targetCount] = target;
	this->targetCount++;
}

void Entity::setPrimaryTarget() {
	int target = -1;
	for (int i=0; i<this->targetCount; i++) {
		if (target == -1 || this->target[i]->getRange() < this->target[target]->getRange()) {
			target = i;
		}
	}
	cout << "Primary target is " + to_string(target) << endl;
	this->primaryTarget = this->target[target];
	if (this->targetInRange(-30, 30)) {
		cout << "Primary target is in range" << endl;
	}
}

bool Entity::targetInRange(float from, float to) {
	float targetBearing =  this->primaryTarget->getBearing() - this->bearing;
	while (targetBearing > 180) {
		targetBearing -= 360;
	}
	while (targetBearing < -180) {
		targetBearing += 360;
	}
	cout << "Target bearing " + to_string(this->primaryTarget->getBearing()) << endl;
	cout << "My bearing " + to_string(this->bearing) << endl;
	cout << "Relative bearing " + to_string(targetBearing) << endl;
	return targetBearing > from && targetBearing < to;
}

int Entity::getX() {
	return this->x;
}

int Entity::getY() {
	return this->y;
}

