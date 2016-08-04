//============================================================================
// Name        : rx.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Node.h"
#include "runner/Runner.h"
#include "impl/Blue.h"
#include "impl/Red.h"
#include <string>
#include "resPath.h"
#include "cleanup.h"

using namespace std;

/*
 * Lesson 5: Clipping Sprite Sheets
 */
//Screen attributes
const int SCREEN_WIDTH  = 200;
const int SCREEN_HEIGHT = 200;

//Setup the clips for our image
SDL_Rect clips[4];

/*
 * Log an SDL error with some error message to the output stream of our choice
 * @param os The output stream to write the message too
 * @param msg The error message to write, format will be msg error: SDL_GetError()
 */
void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}
/*
 * Loads an image into a texture on the rendering device
 * @param file The image file to load
 * @param ren The renderer to load the texture onto
 * @return the loaded texture, or nullptr if something went wrong.
 */
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
		logSDLError(std::cout, "LoadTexture");
	}
	return texture;
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at some destination rect
 * taking a clip of the texture if desired
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param dst The destination rectangle to render the texture too
 * @param clip The sub-section of the texture to draw (clipping rect)
 *		default of nullptr draws the entire texture
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, double rot, SDL_Rect dst, SDL_Rect *clip = nullptr){
	SDL_Point point;
	SDL_RendererFlip flip;
	point.x = 10;
	point.y = 10;
	SDL_RenderCopyEx(ren, tex, clip, &dst, rot - 90, &point, flip);
}
/*
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
 * the texture's width and height and taking a clip of the texture if desired
 * If a clip is passed, the clip's width and height will be used instead of the texture's
 * @param tex The source texture we want to draw
 * @param rend The renderer we want to draw too
 * @param x The x coordinate to draw too
 * @param y The y coordinate to draw too
 * @param clip The sub-section of the texture to draw (clipping rect)
 *		default of nullptr draws the entire texture
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, double rot, int index){
	SDL_Rect *clip = &clips[index];
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	renderTexture(tex, ren, rot, dst, clip);
}

int main(int, char**){
	//Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}

	//Setup our window and renderer
	SDL_Window *window = SDL_CreateWindow("Lesson 5", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		logSDLError(std::cout, "CreateRenderer");
		cleanup(window);
		SDL_Quit();
		return 1;
	}
	SDL_Texture *image = loadTexture("src/image.png", renderer);
	if (image == nullptr){
		cleanup(image, renderer, window);
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	//iW and iH are the clip width and height
	//We'll be drawing only clips so get a center position for the w/h of a clip
	int iW = 20, iH = 20;
	int x = SCREEN_WIDTH / 2 - iW / 2;
	int y = SCREEN_HEIGHT / 2 - iH / 2;

	//Since our clips our uniform in size we can generate a list of their
	//positions using some math (the specifics of this are covered in the lesson)
	for (int i = 0; i < 4; ++i){
		clips[i].x = i / 2 * iW;
		clips[i].y = i % 2 * iH;
		clips[i].w = iW;
		clips[i].h = iH;
	}
	//Specify a default clip to start with
	int useClip = 0;

	SDL_Event e;
	bool quit = false;
	std::srand(time(0)); // use current time as seed for random generator
	Runner *runner = new Runner();
	runner->registerAcp(new Blue(1));
	runner->registerAcp(new Blue(2));
	runner->registerAcp(new Blue(3));
//
	runner->registerAcp(new Red(4));
	runner->registerAcp(new Red(5));
	runner->registerAcp(new Red(6));
//
//
//	runner->registerAcp(new Blue(7));
//	runner->registerAcp(new Blue(8));
//	runner->registerAcp(new Red(9));

	runner->setRenderer(image, renderer);
	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			//Use number input to select which clip should be drawn
			if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
					case SDLK_1:
					case SDLK_KP_1:
						useClip = 0;
						break;
					case SDLK_2:
					case SDLK_KP_2:
						useClip = 1;
						break;
					case SDLK_3:
					case SDLK_KP_3:
						useClip = 2;
						break;
					case SDLK_4:
					case SDLK_KP_4:
						useClip = 3;
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
					default:
						break;
				}
			}
		}
		//Rendering
		SDL_RenderClear(renderer);
		//Draw the image
		//renderTexture(image, renderer, x, y, &clips[useClip]);
		//renderTexture(image, renderer, x + 10, y+ 10, &clips[useClip]);
		//Update the screen
		runner->run();
		SDL_RenderPresent(renderer);
	}
	//Clean up
	cleanup(image, renderer, window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}
