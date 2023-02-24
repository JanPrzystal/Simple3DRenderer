#pragma once
#include "Defs.h"
#include "Vector4.h"
#include "Matrix4.h"

struct Vector3 {
	DECIMAL x, y, z;

	void setValues(DECIMAL x, DECIMAL y, DECIMAL z);

	Vector3(DECIMAL x, DECIMAL y, DECIMAL z);

	Vector3(const Vector3& vec);

	Vector3();

	DECIMAL magnitude();

	Vector4 toVector4();

	Vector3 operator + (DECIMAL number);

	Vector3 operator / (DECIMAL number);

	Vector3 operator * (DECIMAL number);

	DECIMAL operator * (Vector3& vec);

	Vector3 operator * (Matrix4& matrix);

	Vector3 operator - (Vector3& vec);

	Vector3 cross(Vector3& vec);

	Vector3 normalize();
};