#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.h"
#include <iostream>

Player::Player()
{
    texture.loadFromFile("../res/player.png");
    position.x = 50.0f;
    position.y = 200.0f;
    sprite.setTexture(texture);
    sprite.setPosition(position);

    // gravity
    sf::Vector2f velocity(0.0f, 0.0f);
    float maxVelocity = 100;
    float acceleration = 40;
    float friction = 0.93f;

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Player::Update(Player player, float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.velocity.x < player.maxVelocity)
    {
        player.velocity.x -= player.acceleration * dt;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.velocity.x < player.maxVelocity)
    {
        player.velocity.x += player.acceleration * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.velocity.y < player.maxVelocity)
    {
        player.velocity.y -= player.acceleration * dt;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.velocity.y < player.maxVelocity)
    {
        player.velocity.y += player.acceleration * dt;
    }

    sprite.move(player.velocity.x, player.velocity.y);

    player.velocity.x = velocity.x * player.friction;
    player.velocity.y = velocity.y * player.friction;

    std::cout << player.velocity.x;
    std::cout << player.velocity.y;

}
