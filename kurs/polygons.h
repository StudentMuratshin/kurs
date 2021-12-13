#pragma once
#include "circles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#define _USE_MATH_DEFINES
using namespace sf;
using namespace std;

class Polygon : public ConvexShape
{
public:
    Polygon(vector <Vector2f> xy)
    {
        this->setPointCount(xy.size());
        for (int i = 0; i < xy.size(); i++)
        {
            this->setPoint(i, xy[i]);
        }
        this->setFillColor(Color::White);
    }
};


class polygons
{
public:
    vector <Circle> tops_polygon;        //вектор вершин многоугольников
    vector <Polygon> vec_polygons;  //вектор многоугольников
    vector <Vector2f> point_xy; //вектор с координатами вершин многоульников
    bool intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float& x, float& y);
    void Add_top_xy(float x, float y);
    void Add_tops_polygon(float x, float y);
    void Add_polygon(vector<Vector2f> xy);
    void erase_polygon(float xx, float yy, float& x, float& y);
};

