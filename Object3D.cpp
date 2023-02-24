#include "Vector3.h"
#include "Defs.h"

struct Object3D {
	Vector3 position;

	void setPosition(DECIMAL x, DECIMAL y, DECIMAL z) {
		position.x = x;
		position.y = y;
		position.z = z;
	}
	void setPosition(Vector3 vector) {
		this->position = vector;
	}

	Object3D(DECIMAL x, DECIMAL y, DECIMAL z) {
		Object3D();
		setPosition(x, y, z);
	}

	Object3D() {
		position = Vector3();
	}

};
