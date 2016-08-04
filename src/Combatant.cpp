/*
 * Combatant.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#include "Combatant.h"

#include <iostream>

using namespace std;

Combatant::Combatant() {
	// TODO Auto-generated constructor stub
	this->clearTargets();
	this->targetCount = 0;
	this->primaryTarget = NULL;
	this->primaryCombatant = NULL;
	this->bearing = 0;
	this->hp = 100;
	this->x = std::rand() % 200;
	this->y = std::rand() % 200;
}

Combatant::~Combatant() {
	// TODO Auto-generated destructor stub
}

void Combatant::turn(int delta) {
	this->bearing += delta;
	while (this->bearing > 180) {
		this->bearing -= 360;
	}
	while (this->bearing < -180) {
		this->bearing += 360;
	}
}
void Combatant::clearTargets() {
	for (int i=0; i<targetCount; i++) {
		//delete this->target[i];
	}
	this->targetCount = 0;
}

bool Combatant::isDestroyed() {
	return this->hp < 0;
}

void Combatant::registerDamage(int amount) {
	if (this->hp > 0) {
		this->hp -= amount;
		if (this->isDestroyed()) {
			cout << "Combatant is destroyed" << endl;
		}
	}
}

void Combatant::addTarget(Combatant *combatant, Target *target) {
	cout << "Adding target (" + to_string(combatant->getX())  + ", " + to_string(combatant->getY())  + ")" << endl;
	this->combatant[targetCount] = combatant;
	this->target[targetCount] = target;
	this->targetCount++;
}

void Combatant::fireAtPrimaryTarget() {
	if (this->primaryCombatant == NULL) {
		cout << "Primary primaryCombatant is not set" << endl;
		return;
	}
	this->primaryCombatant->registerDamage(DAMAGE);
}

void Combatant::setPrimaryTarget() {
	int target = -1;
	cout << "Have " + to_string(targetCount) + " target(s)" << endl;
	for (int i=0; i<this->targetCount; i++) {
		if (target == -1 || this->target[i]->getRange() < this->target[target]->getRange()) {
			target = i;
		}
	}
	if (target == -1) {
		cout << "No targets remaining" << endl;
		this->primaryTarget = NULL;
		this->primaryCombatant = NULL;
		return;
	}
	this->primaryTarget = this->target[target];
	this->primaryCombatant = this->combatant[target];
	cout << "Primary target is " + to_string(target) << endl;
}

bool Combatant::targetInRange(float from, float to) {
	if (this->primaryTarget == NULL) {
		cout << "Primary target is not set" << endl;
		return false;
	}
	float targetBearing =  this->primaryTarget->getBearing();
	while (targetBearing > 180) {
		targetBearing -= 360;
	}
	while (targetBearing < -180) {
		targetBearing += 360;
	}

	cout << "Target bearing " + to_string(this->primaryTarget->getBearing()) << endl;
	cout << "My bearing " + to_string(this->bearing) << endl;
	return targetBearing > (this->bearing + from) && targetBearing < (this->bearing + to);
}

int Combatant::getX() {
	return this->x;
}

int Combatant::getY() {
	return this->y;
}

int Combatant::getBearing() {
	return this->bearing;
}

