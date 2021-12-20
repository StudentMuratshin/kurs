#include "polygons.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace sf;
using namespace std;

bool Polygons::intersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float& x, float& y)
{
    float Ua, Ub, numerator_a, numerator_b, denominator;

    denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
    if (denominator == 0) {
        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0 && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0)
            return true;
        else false;
    }
    else {
        numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
        numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
        Ua = numerator_a / denominator;
        Ub = numerator_b / denominator;
        x = Ua * x1 + (1 - Ua) * x2;
        y = Ua * y1 + (1 - Ua) * y2;
        return (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1);
    }
}

void Polygons::Add_top_xy(float x, float y)
{
    point_xy.push_back(Vector2f(x, y));
}

void Polygons::Add_tops_polygon(float x, float y)
{
    tops_polygon.push_back(Create_Circle(250, 250, 0, x, y, 3));
}

void Polygons::Add_polygon(vector<Vector2f> xy)
{
    vec_polygons.push_back(Create_Polygon(xy));
}

void Polygons::erase_polygon(float xx, float yy, float& x, float& y)
{
    for (int i = 0; i < vec_polygons.size(); i++)
    {
        int count_intersect = 0;
        for (int j = 0; j < vec_polygons[i].getPointCount() - 1; j++)
        {
            if (intersect(0, 0, xx, yy, vec_polygons[i].getPoint(j).x, vec_polygons[i].getPoint(j).y,
                vec_polygons[i].getPoint(j + 1).x, vec_polygons[i].getPoint(j + 1).y, x, y))
            {
                count_intersect++;
            }
        }

        if (count_intersect % 2 != 0 and count_intersect != 0)
        {
            vec_polygons.erase(vec_polygons.begin() + i);
        }
    }
}