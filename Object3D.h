#pragma once

#include "Vector3.h"
#include "Defs.h"

class Object3D {
public:
	Vector3 position;

	void setPosition(NUMBER x, NUMBER y, NUMBER z);

	void setPosition(Vector3 vector);

	void move(Vector3 vector);

	Object3D(NUMBER x, NUMBER y, NUMBER z);

	Object3D();

};
