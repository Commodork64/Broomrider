#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class Player
{
private:
    // for now I'm going to simply load directly from a file.
    // TODO: User sf::Image to load all images into a central location at
    // the creation of the program and pass them around like that instead.
    sf::Texture texture;
    sf::Sprite sprite;

public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    const float maxVelocity = 20;
    const float acceleration = 4;
    const float friction = 0.93;
    Player();
    void Draw(sf::RenderWindow& window);
    void Update();
};