/*
 * Node.h
 *
 *  Created on: Jul 21, 2016
 *      Author: fox
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(int id);
	virtual ~Node();
	void setTrue(Node *node);
	void setFalse(Node *node);
	void execute();
private:
	int id;
	Node *ifTrue;
	Node *ifFalse;
};

#endif /* NODE_H_ */
