#pragma once
#include <string>
#include "Defs.h"
#include "Matrix4.h"

struct Vector4 {
	DECIMAL x, y, z, w;

	void setValues(DECIMAL x, DECIMAL y, DECIMAL z, DECIMAL w);

	Vector4(DECIMAL x, DECIMAL y, DECIMAL z, DECIMAL w);

	//Vector4(Vector3 vec3, DECIMAL w) {
	//	Vector4(vec3.x, vec3.y, vec3.z, w);
	//}

	Vector4();

	DECIMAL operator * (Vector4& vec);

	Vector4 operator + (DECIMAL number);

	Vector4 operator / (DECIMAL number);


	static Vector4* fillArrayFromMatrix(Matrix4& m, Vector4 arr[]);

	std::string toString();

	Vector4 operator * (Matrix4& matrix);

};
