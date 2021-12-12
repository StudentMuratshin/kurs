#include "light.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace sf;
using namespace std;

void light::phi_plus()
{
	phi++;
}

void light::phi_minus()
{
	phi--;
}

void light::lines(float xx, float yy, int ksi, VertexArray& lines_1)
{
	
	//VertexArray lines_1(LinesStrip, 2);
	
	
	X1 = cos(ksi * M_PI / 180) * xx + sin(ksi * M_PI / 180) * yy;
	Y1 = -sin(ksi * M_PI / 180) * xx + cos(ksi * M_PI / 180) * yy;
	lines_1[0].position = Vector2f(X1, Y1);
	float check = -1;
	float length_polygon = 10000000;
	float min_length_polygon = 10000000;
	if (vec_circles.size() != 0)
	{
		float min_to_cirlce = length(vec_circles[0].getPosition().x, vec_circles[0].getPosition().y);
		cout << min_to_cirlce << endl;
		for (int j = 0; j < vec_circles.size(); ++j)
		{
			float vect_lenght = length(X1, Y1);                             //длина вектора
			Vector2f norm_lenght(X1 / (vect_lenght), Y1 / (vect_lenght));  // нормирую вектор 

			float lenght_circles = length(vec_circles[j].getPosition().x, vec_circles[j].getPosition().y); // c 0;0 до окр

			if (lenght_circles <= min_to_cirlce)
			{
				min_to_cirlce = lenght_circles;
			}


			norm_lenght.x = norm_lenght.x * lenght_circles;    //увеличиваю вектор до длины окружности
			norm_lenght.y = norm_lenght.y * lenght_circles;

			float length_in_circles = check_in_circle(norm_lenght.x, vec_circles[j].getPosition().x, norm_lenght.y, vec_circles[j].getPosition().y); //длина положения конца вектора до окружности

			if (check == 1 and lenght_circles <= min_to_cirlce)
			{
				if (length_in_circles <= vec_circles[j].getRadius() and lenght_circles <= vect_lenght)
				{
					lines_1[0].position = Vector2f(norm_lenght.x, norm_lenght.y);
				}
			}

			if (length_in_circles <= vec_circles[j].getRadius() and lenght_circles <= vect_lenght and check == -1) //проверка находится ли положения конца вектора в окружности
			{
				check = 1;
				lines_1[0].position = Vector2f(norm_lenght.x, norm_lenght.y);  //если да, то принимает координаты, внутри окр-ти
			}
		}
	}
}