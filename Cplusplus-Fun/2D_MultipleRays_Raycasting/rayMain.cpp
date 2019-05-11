#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Boundry.h"
#include "Particle.h"
#include "Ray.h"
#include <iostream>
#include "util.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Raycasting");

    std::vector<Boundry> walls;

    walls.push_back(Boundry(370,100,300,300));
    walls.push_back(Boundry(100,300, 300,300));
    walls.push_back(Boundry(100,100,100,300));
    walls.push_back(Boundry(100,100,300, 30));

    
    walls.push_back(Boundry(0,0,0,400));
    walls.push_back(Boundry(0,0,400,0));
    walls.push_back(Boundry(400,0,400,400));
    walls.push_back(Boundry(400,400,0,400));

    
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

        particle.setPosition(sf::Mouse::getPosition().x - 770, sf::Mouse::getPosition().y - 370);
        particle.update();
        particle.look(walls);

        window.clear();

        particle.show(window);

        for(unsigned long i = 0; i < walls.size(); i++)
        {
            walls[i].draw(window);
        }

        window.display();
    }

    return 0;
}