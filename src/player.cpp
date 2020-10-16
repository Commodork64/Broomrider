#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.h"
#include <iostream>

Player::Player()
{
    texture.loadFromFile("../res/player.png");
    position.x = 200.0f;
    position.y = 200.0f;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    // gravity
    sf::Vector2f velocity(2.0f, 2.0f);
    float maxVelocity = 1000.0f;
    float acceleration = 40.0f;
    float friction = 0.01f;
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Player::Update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x++;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x = velocity.x + acceleration;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity.y = velocity.y - acceleration;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity.y = velocity.y + acceleration;
    }

    sprite.move(velocity.x, velocity.y);

    velocity.x = velocity.x * friction;
    //velocity.y = velocity.y * friction;

    std::cout << "x: ";
    std::cout << velocity.x << std::endl;
    std::cout << "y: ";
    std::cout << velocity.y << std::endl;

}
