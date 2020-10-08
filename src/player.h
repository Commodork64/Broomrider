#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    // for now I'm going to simply load directly from a file.
    // TODO: User sf::Image to load all images into a central location at
    // the creation of the program and pass them around like that instead.
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

public:
    Player();
    void Draw(sf::RenderWindow& window);
};