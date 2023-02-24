#pragma once
#include "Renderer.h"
#include "../SDL2-devel-2.24.2-VC/SDL2-2.24.2/include/SDL.h"
#include "../SDL2-devel-2.24.2-VC/SDL2_ttf-2.20.1/include/SDL_ttf.h"


struct SdlWindowRenderer : public WindowRenderer {
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	SdlWindowRenderer(uint16_t screenWidth, uint16_t screenHeight) : WindowRenderer(screenWidth, screenHeight){
		//WindowRenderer(screenWidth, screenHeight);
		
		this->window = createWindowContext("Software Renderer");
		this->renderer = createRendererContext(window);

		printf("SDL Window Renderer initialized");
		if(init()!=0)
			printf("TTF_Init: %s\n", TTF_GetError());
	}

	~SdlWindowRenderer() {
		//Cleaning up everything.

		SDL_Quit();
	};

	void clearScreen() {
		//Set the draw color...
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		//Clear the screen.
		SDL_RenderClear(renderer);

		setDrawColor(color);
	}

	void present() {
		SDL_RenderPresent(renderer);
	}

	void setDrawColor(Color& color) {
		this->color = color;
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	}

	void drawLine(Vector3& v1, Vector3& v2) {
		//printf("drawLine\n");
		if (SDL_RenderDrawLine(renderer, xToScreenSpace(v1.x), yToScreenSpace(v1.y), xToScreenSpace(v2.x), yToScreenSpace(v2.y)) != 0) {
			printf(SDL_GetError());
		}
	}

	// init ... The init function, it calls the SDL init function.
	int init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			return -1;
		}
		if (TTF_Init() != 0) {
			printf("TTF_Init: %s\n", TTF_GetError());
			return -1;
		}
		return 0;
	}

	// draw ... Draw a series of lines to the screen to create a triangle.
	void drawTriangle(Triangle triangle) {
		triangle.vertices[0] = triangle.vertices[0] * (DECIMAL)WIDTH_HALF;
		triangle.vertices[1] = triangle.vertices[1] * (DECIMAL)WIDTH_HALF;
		triangle.vertices[2] = triangle.vertices[2] * (DECIMAL)WIDTH_HALF;

		drawLine(triangle.vertices[0], triangle.vertices[1]);
		drawLine(triangle.vertices[1], triangle.vertices[2]);
		drawLine(triangle.vertices[0], triangle.vertices[2]);
	}

	void fillTriangle(Triangle& triangle) {
	//	vec2 bbox[2] = find_bounding_box(points);
	//	for (pixel in the bounding box) {
	//		if (inside(points, pixel)) {
	//			put_pixel(pixel);
	//		}
	//	}
	}

	void drawText(const char* text) {
		TTF_Font* font = TTF_OpenFont("./Roboto-Regular.ttf", 16);

		if (font == nullptr) {
			printf("TTF_GetError: %s\n", TTF_GetError());
			return;
		}

		SDL_Color White = { 255, 255, 255 };

		SDL_Surface* surfaceMessage =
			TTF_RenderText_Solid(font, text, White);

		if (surfaceMessage == nullptr) {
			printf("TTF_GetError: %s\n", TTF_GetError());
			return;
		}

		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

		SDL_Rect Message_rect;
		Message_rect.x = 0;   
		Message_rect.y = 0; 
		//todo dynamic rect dimensions
		Message_rect.w = 480; 
		Message_rect.h = 18;

		if(SDL_RenderCopy(renderer, Message, NULL, &Message_rect)!=0)
			printf("TTF_GetError: %s\n", TTF_GetError());

		// Don't forget to free your surface and texture
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
	}

private:
	int xToScreenSpace(DECIMAL x) {
		return (int)(WIDTH_HALF + x);
	}
	int yToScreenSpace(DECIMAL x) {
		return (int)(HEIGHT_HALF - x);
	}

	// createWindowContext ... Creating the window for later use in rendering and stuff.
	SDL_Window* createWindowContext(std::string title) {
		//Declaring the variable the return later.
		SDL_Window* Window = NULL;

		//Creating the window and passing that reference to the previously declared variable. 
		Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

		//Returning the newly creted Window context.
		return Window;
	}

	// createRenderContext ... Creating the rendering context so that I can render things to the Window.
	SDL_Renderer* createRendererContext(SDL_Window* Window) {
		//Declaring the variable for the Renderer context.
		SDL_Renderer* Renderer = NULL;

		//Create the Renderer with the window.
		Renderer = SDL_CreateRenderer(Window, -1, 0);

		//Return the Renderer.
		return Renderer;
	}

};