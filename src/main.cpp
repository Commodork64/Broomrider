#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"

int main()
{
    // setup window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Broomrider");
    sf::RenderWindow& windowPtr = window;
    window.setFramerateLimit(60);

    // create entities
    Player player;

    // enter main program loop while window is open
    while (window.isOpen())
    {
        // check all window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // cycle through events
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::LostFocus:
                    //TODO pause();

                case sf::Event::GainedFocus:
                    // TODO: resume();

                default:
                    break;
            }
        }

        // clears the previous frame
        window.clear(sf::Color::Black);

        player.Draw(windowPtr);

        window.display();
    }
    
    return 0;
}