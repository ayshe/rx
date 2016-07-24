/*
 * TurnNode.h
 *
 *  Created on: Jul 24, 2016
 *      Author: fox
 */

#ifndef TURNNODE_H_
#define TURNNODE_H_

#include "../Node.h"

class TurnNode : public Node {
public:
	TurnNode(int id, int delta);
	virtual ~TurnNode();
private:
	int delta;
	bool eval();
};

#endif /* TURNNODE_H_ */
