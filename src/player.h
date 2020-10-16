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
    sf::Vector2f position;

public:
    Player();
    void Draw(sf::RenderWindow& window);
    void Update(Player player, float dt);
    std::string vecToString(sf::Vector2f v);
    sf::Vector2f velocity;
    float maxVelocity;
    float acceleration;
    float friction;
};