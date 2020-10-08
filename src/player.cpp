#include <SFML/Graphics.hpp>
#include "player.h"

Player::Player()
{
    texture.loadFromFile("../res/player.png");
    position.x = 10.f;
    position.y = 50.f;
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
