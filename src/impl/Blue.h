/*
 * Blue.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#ifndef BLUE_H_
#define BLUE_H_

#include "../Acp.h"

class Blue: public Acp {
public:
	Blue(int id);
	virtual ~Blue();
private:
	void initialise();
};

#endif /* BLUE_H_ */
