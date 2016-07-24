/*
 * Target.h
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#ifndef TARGET_H_
#define TARGET_H_

class Target {
public:
	Target(int id, float bearing, float range);
	virtual ~Target();
	int getId();
	void setId(int id);
	float getBearing();
	void setBearing(float bearing);
	float getRange();
	void setRange(float range);
private:
	int id;
	float bearing;
	float range;
};

#endif /* TARGET_H_ */
