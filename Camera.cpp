#include "Camera.h"

Camera::Camera() {
	Object3D();
	Camera(3.0f/4.0f, 0.1f, 1000.0f, 90.0f);
}
	
Camera::Camera(NUMBER aspectRatio, NUMBER nearPlane, NUMBER farPlane, NUMBER fov) {
	Object3D();
	this->aspectRatio = aspectRatio;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->fov = fov;

	projectionMatrix = Matrix4::getCameraMatrix(aspectRatio, nearPlane, farPlane, fov);
	//std::cout << projectionMatrix.toString() << std::endl;
}

Triangle* Camera::projectTriangle(Triangle t) {
	t.vertices[0] = t.vertices[0] - position;
	t.vertices[1] = t.vertices[1] - position;
	t.vertices[2] = t.vertices[2] - position;

	NUMBER dot = t.findNormal() * t.vertices[0];

	if (dot >= 0.0f) {

		Triangle* projected = new Triangle(
			t.vertices[0] * this->projectionMatrix,
			t.vertices[1] * this->projectionMatrix,
			t.vertices[2] * this->projectionMatrix
		);
		return projected;
	}
	else
		return nullptr;
}

