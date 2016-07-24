/*
 * Runner.h
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */
#ifndef RUNNER_H_
#define RUNNER_H_

#include "../Acp.h"
#include "../constants.h"

class Runner {
public:
	Runner();
	virtual ~Runner();
	void registerAcp(Acp *acp);
	void run();
private:
	void calculatePositions();
	Acp *acp[MAX_ACP_COUNT];
	Node *node[MAX_ACP_COUNT];
	int acpCount;
	int executions;
};

#endif /* RUNNER_H_ */
