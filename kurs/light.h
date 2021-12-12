#pragma once
#include "circles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#define _USE_MATH_DEFINES
class light: circles
{
private:
	float X1, Y1, X2, Y2;
	
public:
	void phi_plus();
	void phi_minus();
	void lines(float xx, float yy, int ksi, VertexArray& lines_1);
	int phi = 30;
	
};

