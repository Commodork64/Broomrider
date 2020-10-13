#include <SFML/Graphics.hpp>
#include "player.h"

Player::Player()
{
    texture.loadFromFile("../res/player.png");
    position.x = 10.f;
    position.y = 50.f;
    sprite.setTexture(texture);
    sprite.setPosition(position);
    speed = 5;

    // gravity
    float velocityX = 0;
    float velocityY = 0;
    float maxVelocity = 100;
    float acceleration = 40;
    float friction = 0.93f;
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Player::Update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (velocityX < maxVelocity)
            {
                velocityX -= acceleration * dt;
            }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (velocityX < maxVelocity)
            {
                velocityX += acceleration * dt;
            }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (velocityY < maxVelocity)
            {
                velocityY -= acceleration * dt;
            }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (velocityY < maxVelocity)
            {
                velocityY += acceleration * dt;
            }
    }

    sprite.move(velocityX, velocityY);

    velocityX = velocityX * friction;
    velocityY = velocityY * friction;

}
