#include "Object3D.cpp"
#include <corecrt_math.h>
#include "Matrix4.h"
#include "Triangle.h"

struct Camera : Object3D{
	Matrix4 projectionMatrix;
	DECIMAL fov;
	DECIMAL nearPlane;
	DECIMAL farPlane;
	DECIMAL aspectRatio;

	Camera() {
		Object3D();
		Camera(3.0f/4.0f, 0.1f, 1000.0f, 90.0f);
	}
	Camera(DECIMAL aspectRatio, DECIMAL nearPlane, DECIMAL farPlane, DECIMAL fov) {
		Object3D();
		this->aspectRatio = aspectRatio;
		this->nearPlane = nearPlane;
		this->farPlane = farPlane;
		this->fov = fov;

		projectionMatrix = Matrix4::getCameraMatrix(aspectRatio, nearPlane, farPlane, fov);
		//std::cout << projectionMatrix.toString() << std::endl;
	}

	Triangle* projectTriangle(Triangle& t, DECIMAL zOffset) {
		t.vertices[0].z += zOffset;
		t.vertices[1].z += zOffset;
		t.vertices[2].z += zOffset;

		Vector3 relativeToCamera = (t.vertices[0] - this->position);//for some reason putting this as operation in next line instead of variable causes error
		DECIMAL dot = t.findNormal() * relativeToCamera;

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

};

