/*
 * Entity.h
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "constants.h"
#include "Target.h"

class Entity {
public:
	Entity();
	virtual ~Entity();
	int getX();
	int getY();
	void clearTargets();
	void addTarget(Target *target);
	void setPrimaryTarget();
	bool targetInRange(float from, float to);
	void turn(int delta);
private:
	int x;
	int y;
	Target *primaryTarget;
	float bearing;
	Target *target[MAX_ACP_COUNT];
	int targetCount;
};

#endif /* ENTITY_H_ */
