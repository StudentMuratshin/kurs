#pragma once
#include "circles.h"
#include "polygons.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#define _USE_MATH_DEFINES
class light: polygons,circles
{
private:
	float X1, Y1, X2, Y2;
	
public:
	void phi_plus();
	void phi_minus();
	void lines(float xx, float yy, int ksi, VertexArray& lines_1, vector<Circle> vec_circles, vector<Polygon> vec_polygons, float& x, float& y);
	int phi = 30;
};

