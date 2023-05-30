#pragma once

#include "Matrix4.h"
#include "Triangle.h"
#include "Object3D.h"

class Camera : public Object3D {
public:
	Matrix4 projectionMatrix;
	NUMBER fov;
	NUMBER nearPlane;
	NUMBER farPlane;
	NUMBER aspectRatio;

	Camera();

	Camera(NUMBER aspectRatio, NUMBER nearPlane, NUMBER farPlane, NUMBER fov);

	Triangle* projectTriangle(Triangle t);

};