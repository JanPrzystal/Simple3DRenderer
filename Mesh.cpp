#include "Mesh.h"

Mesh::Mesh(std::vector<Triangle> triangles) {
	this->triangles = triangles;
}

Mesh* rotateMesh(Mesh* mesh, Matrix4& rotation) {
	std::vector<Triangle>& triangles = mesh->triangles;
	for (Triangle& t : triangles) {
		t.vertices[0] = t.vertices[0] * rotation;
		t.vertices[1] = t.vertices[1] * rotation;
		t.vertices[2] = t.vertices[2] * rotation;
	}

	return mesh;
}