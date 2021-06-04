#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Boundry.h"
#include "Ray.h"
#include <iostream>
#include "util.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "Raycasting");
    Boundry wall(300,100,300,300);
    Ray ray(100,200);
    sf::CircleShape rayHit(8);
    rayHit.setFillColor(sf::Color::Yellow);
    rayHit.setPosition(0,0);
    bool setShow = false;

    // sf::VertexArray lines(sf::LinesStrip, 2);
    // lines[0].position = sf::Vector2f(100, 100);
    // lines[1].position = sf::Vector2f(200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ray.lookAt(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        ray.update();
        Vector2f point = ray.cast(wall);
        if(point != Vector2f(-1,-1))
        {
            rayHit.setPosition(point.x - 8, point.y - 8);
            setShow = true;
        }
        else
        {
            setShow = false;
        }

        window.clear();
        // window.draw(lines);
        wall.draw(window);
        ray.getRayLine().draw(window);

        if(setShow){
            window.draw(rayHit);
        }

        window.display();
    }

    return 0;
}
