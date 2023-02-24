#pragma once
#include "Vector3.h"

struct Triangle {
	Vector3 vertices[3];

	Triangle(Vector3 v1, Vector3 v2, Vector3 v3);

	Triangle(const Triangle& triangle);

	Vector3 findNormal();
};