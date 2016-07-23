/*
 * Acp.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */

#ifndef ACP_H_
#define ACP_H_

#include "constants.h"
#include "Node.h"

class Acp {
public:
	typedef Acp super;
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
};

#endif /* ACP_H_ */
