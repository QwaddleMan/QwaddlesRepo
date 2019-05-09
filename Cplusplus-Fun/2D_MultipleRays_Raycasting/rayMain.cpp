#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Boundry.h"
#include "Particle.h"
#include "Ray.h"
#include <iostream>
#include "util.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "Raycasting");
    Boundry wall(300,100,300,300);
    
    Particle particle(200,200);
    std::cout<<particle.rays.size()<<std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        particle.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
        particle.update();
        particle.look(wall);

        window.clear();

        particle.show(window);
        wall.draw(window);

        window.display();
    }

    return 0;
}