/*
 * Acp.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#ifndef ACP_H_
#define ACP_H_

#include "constants.h"
#include "Entity.h"
#include "Node.h"
#include "Target.h"
#include "nodes/RangeNode.h"
#include "nodes/TurnNode.h"


class Acp: public Entity {
public:
	Acp();
	virtual ~Acp();
	Node *getEntrypoint();
protected:
	void setEntrypoint(Node *node);
	void addNode(Node *node);
	virtual void initialise();
private:
	int nodeCount;
	Node *entrypoint;
	Node *nexus[MAX_NEXUS_SIZE];
	int hp;
};

#endif /* ACP_H_ */
