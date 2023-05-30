#pragma once
#include "Triangle.h"
#include "Camera.h"
#include "Mesh.h"
#include "Color.h"
//#include<thread>

class WindowRenderer {

public:
	uint16_t SCREEN_WIDTH;
	uint16_t SCREEN_HEIGHT;
	uint16_t WIDTH_HALF;
	uint16_t HEIGHT_HALF;

	Color color;

	WindowRenderer(uint16_t screenWidth, uint16_t screenHeight) {
		SCREEN_WIDTH = screenWidth;
		SCREEN_HEIGHT = screenHeight;
		WIDTH_HALF = SCREEN_WIDTH / 2;
		HEIGHT_HALF = SCREEN_HEIGHT / 2;

	}
	WindowRenderer() = default;

	virtual int init() = 0;
	virtual void clearScreen() = 0;
	virtual void setDrawColor(Color& color) = 0;
	virtual void drawLine(Vector3& v1, Vector3& v2) = 0;
	virtual void drawTriangle(Triangle triangle) = 0;
	virtual void fillTriangle(Triangle& triangle) = 0;
	virtual void drawText(const char* text) = 0;
	virtual void present() = 0;//show drawn data on screen

	void drawTriangle(Triangle triangle, bool fill);

	void drawMesh(Mesh* mesh, Color& color, Camera& camera);	
};