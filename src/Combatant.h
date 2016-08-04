/*
 * Combatant.h
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#ifndef COMBATANT_H_
#define COMBATANT_H_

#include "constants.h"
#include "Target.h"

class Combatant {
public:
	Combatant();
	virtual ~Combatant();
	int getX();
	int getY();
	int getBearing();
	void clearTargets();
	void addTarget(Combatant *combatant, Target *target);
	void setPrimaryTarget();
	bool targetInRange(float from, float to);
	void turn(int delta);
	bool isDestroyed();
	void registerDamage(int amount);
	void fireAtPrimaryTarget();
private:
	int x;
	int y;
	Target *primaryTarget;
	Combatant *primaryCombatant;
	float bearing;
	Target *target[MAX_ACP_COUNT];
	Combatant *combatant[MAX_ACP_COUNT];
	int targetCount;
	int hp;
};

#endif /* COMBATANT_H_ */
