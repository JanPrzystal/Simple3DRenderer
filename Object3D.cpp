#include "Object3D.h"

void Object3D::setPosition(NUMBER x, NUMBER y, NUMBER z) {
	position.x = x;
	position.y = y;
	position.z = z;
}
void Object3D::setPosition(Vector3 vector) {
	this->position = vector;
}

Object3D::Object3D(NUMBER x, NUMBER y, NUMBER z) {
	Object3D();
	setPosition(x, y, z);
}

Object3D::Object3D() {
	position = Vector3();//todo check memory
}

void Object3D::move(Vector3 vector) {
	position.x += vector.x;
	position.y += vector.y;
	position.z += vector.z;
}
