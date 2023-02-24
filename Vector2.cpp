//#pragma once
//#ifndef STRING
//#include <string>
//#define STRING
//#endif // !"STRING"
//
//#ifndef MATH
//#include <corecrt_math.h>
//#define MATH
//#endif
//
//struct Vector2 {
//	DECIMAL x, y, magnitude;
//
//	void setValues(DECIMAL x, DECIMAL y) {
//		this->x = x;
//		this->y = y;
//		magnitude = sqrtf(x * x + y * y);
//	}
//	Vector2(DECIMAL x, DECIMAL y) {
//		setValues(x, y);
//	}
//
//	Vector2(const Vector2& vec) {
//		this->x = vec.x;
//		this->y = vec.y;
//		this->magnitude = vec.magnitude;
//	}
//
//	Vector2() {
//		setValues(0.0f, 0.0f);
//	}
//
//	Vector2 cross (Vector2& vec) {
//
//	}
//
//	//Vector3 operator + (DECIMAL number) {
//	//	return Vector3(this->x + number, this->y + number, this->z + number);
//	//}
//	//Vector3 operator / (DECIMAL number) {
//	//	return Vector3(this->x / number, this->y / number, this->z / number);
//	//}
//	//Vector3 operator * (DECIMAL number) {
//	//	return Vector3(this->x * number, this->y * number, this->z * number);
//	//}
//
//	std::string toString() {
//		return "Vector2: [" + std::to_string(x) + ", " + std::to_string(y) + "]";
//	}
//};