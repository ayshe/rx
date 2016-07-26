/*
 * Red.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#ifndef RED_H_
#define RED_H_

#include "../Acp.h"

class Red: public Acp {
public:
	Red(int id);
	virtual ~Red();
private:
	void initialise();
};

#endif /* RED_H_ */
