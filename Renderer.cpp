#include "Renderer.h"

void WindowRenderer::drawTriangle(Triangle triangle, bool fill) {
	drawTriangle(triangle);
	if (fill)
		fillTriangle(triangle);
}

void WindowRenderer::drawMesh(Mesh* mesh, Color& color, Camera& camera) {
	//printf("drawMesh\n");
	std::vector<Triangle> triangles = mesh->triangles;
	for (Triangle t : triangles) {
		//Triangle copy(t);
		Triangle* projected = camera.projectTriangle(t);
		if (projected != nullptr) {
			drawTriangle(*projected);
		}
		delete projected;

	}
}