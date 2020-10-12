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
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Player::MovePlayer(int speed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(-speed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(0, -speed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0, speed);
    }
}
