#pragma once
#include "Triangle.h"
#include <vector>

struct Mesh {
	std::vector<Triangle> triangles;

	Mesh(std::vector<Triangle> triangles);

};

Mesh* rotateMesh(Mesh* mesh, Matrix4& rotation);