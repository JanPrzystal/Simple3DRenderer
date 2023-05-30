#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <string>

void Vector3::setValues(NUMBER x, NUMBER y, NUMBER z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(NUMBER x, NUMBER y, NUMBER z) {
	setValues(x, y, z);
}

Vector3::Vector3(const Vector3& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

Vector3::Vector3() {
	setValues(0.0f, 0.0f, 0.0f);
}

NUMBER Vector3::magnitude() {
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector4 Vector3::toVector4() {
	return Vector4(this->x, this->y, this->z, (NUMBER)1);
}

Vector3 Vector3::operator + (NUMBER number) {
	return Vector3(this->x + number, this->y + number, this->z + number);
}

Vector3 Vector3::operator / (NUMBER number) {
	return Vector3(this->x / number, this->y / number, this->z / number);
}

Vector3 Vector3::operator * (NUMBER number) {
	return Vector3(this->x * number, this->y * number, this->z * number);
}

NUMBER Vector3::operator * (Vector3& vec) {//dot product
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vector3 Vector3::operator * (Matrix4& matrix) {
	Vector4 vec4 = toVector4();
	vec4 = vec4 * matrix;
	//std::cout << "matrix mul " << vec4.toString() << std::endl;
	vec4 = vec4 / vec4.w;
	//std::cout << "divided " << vec4.toString() << std::endl;

	return Vector3(vec4.x, vec4.y, vec4.z);
}

Vector3 Vector3::operator + (Vector3& vec) {
	return Vector3(
		this->x + vec.x,
		this->y + vec.y,
		this->z + vec.z
	);
}

Vector3 Vector3::operator - (Vector3& vec) {
	return Vector3(
		this->x - vec.x,
		this->y - vec.y,
		this->z - vec.z
	);
}

Vector3 Vector3::cross(Vector3& vec) {
	Vector3 normal(
		this->y * vec.z - this->z * vec.y,
		this->z * vec.x - this->x * vec.z,
		this->x * vec.y - this->y * vec.x
	);
	return normal;
}

Vector3 Vector3::normalize() {
	return *this / magnitude();
}

	//std::string toString() {
	//	return "Vector3: [" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
	//}
