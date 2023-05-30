#include "Triangle.h"

//#include <string>

Triangle::Triangle(Vector3 v1, Vector3 v2, Vector3 v3) {
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
}

Triangle::Triangle(const Triangle& triangle) {
	vertices[0] = Vector3(triangle.vertices[0]);
	vertices[1] = Vector3(triangle.vertices[1]);
	vertices[2] = Vector3(triangle.vertices[2]);
}

Vector3 Triangle::findNormal() {
	Vector3 l1, l2;
	l1 = vertices[1] - vertices[0];
	l2 = vertices[2] - vertices[0];
	Vector3 normal = l1.cross(l2).normalize();
	return normal;
}
	
	//std::string toString() {
	//	return "Triangle: [\n" + vertices[0].toString() + ",\n" + vertices[1].toString() + ",\n" + vertices[2].toString() + "\n]";
	//}


