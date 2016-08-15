/*
 * Runner.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: fox
 */
#include <stddef.h>
#include <iostream>
#include <string>
#include <tgmath.h>

#include "Runner.h"
#include "../Acp.h"

using namespace std;

Runner::Runner() : node() {
	// TODO Auto-generated constructor stub
	this->acpCount = 0;
}

Runner::~Runner() {
	// TODO Auto-generated destructor stub
}

void Runner::registerAcp(Acp *acp) {
	if (this->acpCount > MAX_ACP_COUNT) {
		return;
	}
	this->acp[this->acpCount] = acp;
	this->acpCount++;
}

void Runner::dropAll() {
	this->acpCount = 0;
}

void Runner::run() {
	this->calculatePositions();
	for (int i=0; i<this->acpCount; i++) {
		Acp *thisACP = this->acp[i];
		if (!thisACP->isDestroyed()) {
			Node *toExecute = this->node[i];
			if (toExecute == NULL) {
				toExecute = this->acp[i]->getEntrypoint();
			}
			if (toExecute != NULL) {
				this->node[i] = toExecute->execute();
			}
		}
	}
}

void Runner::draw() {
	this->calculatePositions();
	for (int i=0; i<this->acpCount; i++) {
		Acp *thisACP = this->acp[i];
		this->render(thisACP);
	}
}

void Runner::calculatePositions() {
	for (int i=0; i<this->acpCount; i++) {
		Acp *thisACP = this->acp[i];
		thisACP->clearTargets();
		for (int t=0; t<this->acpCount; t++) {
			if (t != i) {
				Acp *thatACP = this->acp[t];
				if (!thatACP->isDestroyed()) {
					float bearing = (atan2(thatACP->getY() - thisACP->getY(), thatACP->getX() - thisACP->getX())) * 180 / M_PI;
					float range = sqrt((thatACP->getX() - thisACP->getX())*(thatACP->getX() - thisACP->getX()) + (thatACP->getY() - thisACP->getY())*(thatACP->getY()- thisACP->getY()));
					thisACP->addTarget(thatACP, new Target(t, bearing, range));
					cout << "I am ACP" + to_string(thisACP->getId()) + ":: Target ACP" + to_string(thatACP->getId()) + " bearing " + to_string(bearing) + " range " + to_string(range) << endl;
				}
			}
		}
		thisACP->setPrimaryTarget();
	}
}

void Runner::setRenderer(SDL_Texture *image, SDL_Renderer *renderer) {
	this->image = image;
	this->renderer = renderer;
}

void Runner::render(Acp* acp) {
	renderTexture(this->image, this->renderer, acp->getX(), acp->getY(), acp->getBearing(), acp->getClip());
}

