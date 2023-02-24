#pragma once

#include "Defs.h"
static DECIMAL PI = 3.14159f;

struct Matrix4 {
	DECIMAL matrix[4][4];

	Matrix4();

	Matrix4(Matrix4 &matrix);

	Matrix4(DECIMAL m00, DECIMAL m11, DECIMAL m22, DECIMAL m33);

	static Matrix4 getCameraMatrix(DECIMAL aspectRatio, DECIMAL nearPlane, DECIMAL farPlane, DECIMAL fov);
};
