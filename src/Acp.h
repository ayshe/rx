/*
 * Acp.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#ifndef ACP_H_
#define ACP_H_

#include "constants.h"
#include "Combatant.h"
#include "Node.h"
#include "Target.h"
#include "nodes/RangeNode.h"
#include "nodes/TurnNode.h"
#include "nodes/FireNode.h"


class Acp: public Combatant {
public:
	Acp(int id);
	virtual ~Acp();
	int getId();
	int getClip();
	Node *getEntrypoint();
protected:
	void setEntrypoint(Node *node);
	void addNode(Node *node);
	virtual void initialise();
	int clip;
private:
	int id;
	int nodeCount;
	Node *entrypoint;
	Node *nexus[MAX_NEXUS_SIZE];
};

#endif /* ACP_H_ */
