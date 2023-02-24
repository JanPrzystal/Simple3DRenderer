#pragma once
#include <cstdint>

struct Color {
	static Color white;

	uint8_t r, g, b, a;

	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	Color();
};