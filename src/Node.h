/*
 * Node.h
 *
 *  Created on: Jul 21, 2016
 *      Author: fox
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include "Entity.h"


class Node {
public:
	Node(int id);
	virtual ~Node();
	void setTrue(Node *node);
	void setFalse(Node *node);
	Node* execute();
	void setEntity(Entity *entity);
	Entity *getEntity();
protected:
	Entity *entity;
	int id;
	Node *ifTrue;
	Node *ifFalse;
private:
	virtual bool eval();
};

#endif /* NODE_H_ */
