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
#include <SDL.h>
#include <SDL_image.h>

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, double rot, int index);

class Runner {
public:
	Runner();
	virtual ~Runner();
	void registerAcp(Acp *acp);
	void run();
	void setRenderer(SDL_Texture *image, SDL_Renderer *renderer);
private:
	void calculatePositions();
	Acp *acp[MAX_ACP_COUNT];
	Node *node[MAX_ACP_COUNT];
	int acpCount;
	SDL_Texture *image;
	SDL_Renderer *renderer;
	void render(Acp* acp);
};

#endif /* RUNNER_H_ */
