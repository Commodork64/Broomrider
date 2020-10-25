#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.hpp"
#include <iostream>

Player::Player()
{
    texture.loadFromFile("../res/player.png");
    position.x = 200.0f;
    position.y = 200.0f;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Player::Update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && velocity.x >= -maxVelocity)
    {
        velocity.x -= acceleration;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && velocity.x <= maxVelocity)
    {
        velocity.x += acceleration;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && velocity.y >= -maxVelocity)
    {
        velocity.y -= acceleration;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && velocity.y <= maxVelocity)
    {
        velocity.y += acceleration;
    }

    sprite.move(velocity.x, velocity.y);

    velocity.x = velocity.x * friction;
    velocity.y = velocity.y * friction;

    std::cout << "x: ";
    std::cout << velocity.x << std::endl;
    std::cout << "y: ";
    std::cout << velocity.y << std::endl;
}
