/*
 * rangeNode.h
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#ifndef RANGENODE_H_
#define RANGENODE_H_

#include "../Node.h"

class RangeNode: public Node {
public:
	RangeNode(int id, float from, float to);
	virtual ~RangeNode();
private:
	float from;
	float to;
	bool eval();
};

#endif /* RANGENODE_H_ */
