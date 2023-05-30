#include "Matrix4.h"
#include <corecrt_math.h>

#include <iostream>
//#include <sstream>

Matrix4::Matrix4() {
	memset(this->matrix, 0, sizeof(this->matrix));
}

Matrix4::Matrix4(Matrix4 &matrix) {
	memcpy(this->matrix, matrix.matrix, sizeof(this->matrix));
}

Matrix4::Matrix4(NUMBER m00, NUMBER m11, NUMBER m22, NUMBER m33) : Matrix4() {
	this->matrix[0][0] = m00;
	this->matrix[1][1] = m11;
	this->matrix[2][2] = m22;
	this->matrix[3][3] = m33;
}

Matrix4 Matrix4::getCameraMatrix(NUMBER aspectRatio, NUMBER nearPlane, NUMBER farPlane, NUMBER fov) {
	NUMBER fovRad = 1.0f / tanf(fov * 0.5f / 180.0f * PI);

	//printf("in tan %f\n", (fov * 0.5f / 180.0f * PI));
	//printf("tan %f\n", tanf(fov * 0.5f / 180.0f * PI));
	//printf("fovRad %f\n", fovRad);

	Matrix4 cameraMatrix(aspectRatio * fovRad, fovRad, farPlane / (farPlane - nearPlane), 0.0f);
	cameraMatrix.matrix[3][2] = (-farPlane * nearPlane) / (farPlane - nearPlane);
	cameraMatrix.matrix[2][3] = 1.0f;

	return cameraMatrix;
}

	//std::string toString() {
	//	std::stringstream stream;
	//	for (uint8_t i = 0; i < 4; i++) {
	//		stream << "[";
	//		for (uint8_t j = 0; j < 4; j++) {
	//			stream << matrix[i][j] << ", ";
	//		}
	//		stream << "]\n";
	//	}
	//	return stream.str();
	//}
