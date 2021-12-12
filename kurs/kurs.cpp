#include "circles.h"
#include "light.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define _USE_MATH_DEFINES
using namespace sf;
using namespace std;



int main()
{
    int fps = 30, type = 2;
    float x, y;
    srand(time(NULL));
    circles circles;
    light light;

    RenderWindow window(VideoMode(), "курсовая", Style::Fullscreen);
    window.setFramerateLimit(fps);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

            if (event.type == Event::Closed)
                window.close();
        }
        //добавление объектов при помощи мыши
        Vector2i position = Mouse::getPosition();

        if (Keyboard::isKeyPressed(Keyboard::Space))            //менять объекты на пробел
        {
            type = (type + 1) % 2;
        }

        if (type == 0)
        {
            static bool lock_click;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && lock_click != true)
                {
                    circles.Add_circles(position.x, position.y); //добавляет окру-ти в вектор

                    lock_click = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    lock_click = false;
                }
            }
        }

        if (Mouse::isButtonPressed(Mouse::Right))
        {
            circles.erase_circle(position.x, position.y);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) 
        {
            light.phi_plus();
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) 
        {
            light.phi_minus();
        }

        window.clear(Color::Black);
        VertexArray lines_1(LinesStrip, 2);
        int ksi = light.phi;

        for (int i = 0; i < 2 * light.phi; ++i)
        {
            ksi--;
            light.lines(position.x, position.y, ksi, lines_1);
            window.draw(lines_1);
        }

        for (auto& s : circles.vec_circles)
        {
            window.draw(s);
        }

        window.display();
    }

    return 0;
}