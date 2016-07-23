//============================================================================
// Name        : rx.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Node.h"
#include "runner/Runner.h"
#include "impl/Blue.h"
#include "impl/Red.h"

using namespace std;

Node* entrypoint;

void create() {
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);

	node1->setTrue(node2);
	node1->setFalse(node3);

	node2->setTrue(node3);

	node3->setFalse(node2);

	entrypoint = node1;
}

int main() {
	Runner *runner = new Runner();
	runner->registerAcp(new Red());
	runner->registerAcp(new Blue());
	runner->run();
	return 0;
}
