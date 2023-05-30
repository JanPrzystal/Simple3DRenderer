#include <iostream>
#include <chrono>
#include <string.h>
//#include <SDL.h>
#include "SdlWindowRenderer.cpp"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 600;
const int WIDTH_HALF = SCREEN_WIDTH / 2;
const int HEIGHT_HALF = SCREEN_HEIGHT / 2;

const int targetFrameDuration = 16;

int main(int argc, char* args[]) {
	//initialize the renderer
	SdlWindowRenderer* wr = new SdlWindowRenderer(SCREEN_WIDTH, SCREEN_HEIGHT);

	Color color = Color::white;

	(*wr).setDrawColor(color);

	//setup camera
	NUMBER aspectRatio = (NUMBER)SCREEN_WIDTH / (NUMBER)SCREEN_HEIGHT;
	const NUMBER nearPlane = 0.1f;
	const NUMBER farPlane = 1000.0f;
	const NUMBER fov = 120.0f;
	Camera camera(aspectRatio, nearPlane, farPlane, fov);

	//create points in 3d space
	Vector3 v1(-1.0f, 1.0f, 1.0f);
	Vector3 v2(-1.0f, -1.0f, 1.0f);
	Vector3 v3(1.0f, -1.0f, 1.0f);
	Vector3 v4(1.0f, 1.0f, 1.0f);
	Vector3 v5(-1.0f, 1.0f, -1.0f);
	Vector3 v6(-1.0f, -1.0f, -1.0f);
	Vector3 v7(1.0f, -1.0f, -1.0f);
	Vector3 v8(1.0f, 1.0f, -1.0f);

	//connect points to form triangles
	Triangle t1(v3, v2, v1);
	Triangle t2(v1, v4, v3);
	Triangle t3(v1, v2, v5);
	Triangle t4(v5, v2, v6);
	Triangle t5(v8, v3, v4);
	Triangle t6(v8, v7, v3);
	Triangle t7(v5, v6, v7);
	Triangle t8(v7, v8, v5);
	Triangle t9(v5, v4, v1);//t1
	Triangle t10(v8, v4, v5);//t2
	Triangle t11(v2, v3, v6);//b1
	Triangle t12(v7, v6, v3);//b2

	//create a mesh from the triangles
	std::vector<Triangle> triangles = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 };
	Mesh* mesh = new Mesh(triangles);

	//init end time of the previous frame to calculate frame duration
	uint64_t previousTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	int counter = 0;//frame counter
	NUMBER rotation = (PI / 120.0f);//rotation that will be applied each frame to the mesh

	bool incrementCounter = false; // signals whether to increment or decrement the counter at the end of the loop
	int loopMax = 400; // how many loops before switch

	while (counter <= loopMax && counter >= 0) {
		//get time at the start of frame
		uint64_t  beforeTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		//std::cout << "last frame duration " << beforeTime - previousTime << "ms" << std::endl;
		
		//clear the screen so a new frame can be drawn
		wr->clearScreen();

		//create rotation matrices
		Matrix4 rotX, rotY, rotZ;
		
		rotX = Matrix4(cosf(rotation * 0.8f), cosf(rotation * 0.8f), 1.0f, 1.0f);
		rotX.matrix[0][1] = sinf(rotation * 0.8f);
		rotX.matrix[1][0] = -sinf(rotation * 0.8f);

		rotY = Matrix4(cosf(rotation), 1.0f, cosf(rotation), 1.0f);
		rotY.matrix[0][2] = sinf(rotation);
		rotY.matrix[2][0] = -sinf(rotation);

		//Rotation along Z axis disabled
		//rotZ = Matrix4(1.0f, cosf(rotation * 0.5f), cosf(rotation * 0.5f), 1.0f);
		//rotZ.matrix[1][2] = sinf(rotation * 0.5f);
		//rotZ.matrix[2][1] = -sinf(rotation * 0.5f);

		//rotate the mesh
		rotateMesh(mesh, rotX);
		rotateMesh(mesh, rotY);

		//project and draw the mesh
		camera.setPosition(Vector3(0,0, -(600.0f - counter) / 100.0f));
		wr->drawMesh(mesh, color, camera);

		//get time after operation and calculate the duration of rendering
		uint64_t  afterTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		uint64_t dTime = afterTime - beforeTime;

		std::string lastText = "last frame duration " + std::to_string(beforeTime - previousTime);
		std::string durationText = "frame " + std::to_string(counter) + "; duration " + std::to_string(dTime);
		std::string text = lastText + "\n" + durationText;
		//printf(text.c_str());

		//draw the text with information about frame duration on screen
		wr->drawText(text.c_str());
		//std::cout << "frame " << counter << "; duration " << afterTime - beforeTime << "ms" << std::endl;

		//present the drawn items on screen
		wr->present();

		previousTime = beforeTime;

		//calculate time after the frame is finished
		afterTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		dTime = afterTime - beforeTime;

		//calculate the delay needed to make the frame last ~16ms
		uint32_t delay = 0;
		if (dTime < targetFrameDuration)
			delay = targetFrameDuration - dTime;
		SDL_Delay(delay);

		if (counter == loopMax || counter == 0)
			incrementCounter = !incrementCounter;

		if (incrementCounter)
			counter++;
		else
			counter--;
	}

	wr->clearScreen();
	std::string endText = "end";
	wr->drawText(endText.c_str());
	wr->present();

	//Adding a delay.
	SDL_Delay(1 * 1000);

	delete mesh;
	delete wr;

	return 0;
}

