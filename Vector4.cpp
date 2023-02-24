#pragma once
#include "Vector4.h"


void Vector4::setValues(DECIMAL x, DECIMAL y, DECIMAL z, DECIMAL w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(DECIMAL x, DECIMAL y, DECIMAL z, DECIMAL w) {
	setValues(x, y, z, w);
}

//Vector4(Vector3 vec3, DECIMAL w) {
//	Vector4(vec3.x, vec3.y, vec3.z, w);
//}

Vector4::Vector4() {
	setValues(0.0f, 0.0f, 0.0f, 0.0f);
}

DECIMAL Vector4::operator * (Vector4& vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
}
Vector4 Vector4::operator + (DECIMAL number) {
	return Vector4(this->x + number, this->y + number, this->z + number, this->w + number);
}
Vector4 Vector4::operator / (DECIMAL number) {
	return Vector4(this->x / number, this->y / number, this->z / number, this->w / number);
}

Vector4* Vector4::fillArrayFromMatrix(Matrix4& m, Vector4 arr[]) {//columns to vectors
	arr[0] = Vector4(m.matrix[0][0], m.matrix[1][0], m.matrix[2][0], m.matrix[3][0]);
	arr[1] = Vector4(m.matrix[0][1], m.matrix[1][1], m.matrix[2][1], m.matrix[3][1]);
	arr[2] = Vector4(m.matrix[0][2], m.matrix[1][2], m.matrix[2][2], m.matrix[3][2]);
	arr[3] = Vector4(m.matrix[0][3], m.matrix[1][3], m.matrix[2][3], m.matrix[3][3]);
	return arr;
}

std::string Vector4::toString() {
	return "Vector4: [" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + "]";
}

Vector4 Vector4::operator * (Matrix4& matrix) {
	Vector4 mat[4];
	fillArrayFromMatrix(matrix, mat);

	//std::cout << toString() << " * " << mat[0].toString() << " = " << *this * mat[0] << std::endl;
	//std::cout << toString() << " * " << mat[1].toString() << " = " << *this * mat[1] << std::endl;
	//std::cout << toString() << " * " << mat[2].toString() << " = " << *this * mat[2] << std::endl;
	//std::cout << toString() << " * " << mat[3].toString() << " = " << *this * mat[3] << std::endl;

	return Vector4(
		*this * mat[0],
		*this * mat[1],
		*this * mat[2],
		*this * mat[3]
	);
}

