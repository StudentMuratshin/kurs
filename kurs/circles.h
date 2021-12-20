#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#define _USE_MATH_DEFINES
using namespace sf;
using namespace std;


class Create_Circle : public CircleShape
{
public:
    Create_Circle(int R, int G, int B, float x, float y, int r)
    {
        this->setFillColor(Color(R, G, B));
        this->setRadius(r);
        this->setPosition(x, y);
        this->setOrigin(r, r);
    }
};


class Circles
{
public:
    vector <Create_Circle> vec_circles;    //вектор окружностей
	void Add_circles(float x, float y); //добавление окр-ей
    void erase_circle(float x, float y);
    float check_in_circle(float x1, float x2, float y1, float y2);
    float length(float x1, float x2);
};

