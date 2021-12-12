#include "circles.h"
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



void circles::Add_circles(float x, float y)
{
    vec_circles.push_back(Circle(250, 250, 0, x, y, 50));  //добавляет окру-ти в вектор
}

float circles::check_in_circle(float x1, float x2, float y1, float y2)
{
    return(sqrt((pow(x1 - x2, 2)) + (pow(y1 - y2, 2))));
}

void circles::erase_circle(float x, float y)
{
    for (int i = 0; i < vec_circles.size(); i++)
    {

        float length = check_in_circle(x, vec_circles[i].getPosition().x,
            y, vec_circles[i].getPosition().y);
        if (length <= vec_circles[i].getRadius())
        {
            vec_circles.erase(vec_circles.begin() + i);
        }
    }
}

float circles::length(float x1, float x2)
{
    return (sqrt(pow(x1, 2) + pow(x2, 2)));
}