/*
 * FireNode.h
 *
 *  Created on: Jul 26, 2016
 *      Author: fox
 */

#ifndef FIRENODE_H_
#define FIRENODE_H_

#include "../Node.h"

class FireNode: public Node  {
public:
	FireNode(int id);
	virtual ~FireNode();
	bool eval();
};

#endif /* FIRENODE_H_ */
