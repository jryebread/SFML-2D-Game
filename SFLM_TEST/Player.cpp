#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Projectile.h"

Player::Player()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setFillColor(sf::Color::Blue);
	sprite.setPosition(400, 400);
	sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 0, 32, 52));
}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
}

void Player::frameCounter()
{
	if (counterIncrement == 3)
		counterIncrement = 0;
	counterIncrement++;
}

void Player::updateAnimation()
{
	
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 49 * 3, 32, 52));
		m_direction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 0, 32, 52));
		m_direction = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 49, 32, 52));
		m_direction = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 48 * 2, 32, 52));
		m_direction = 4;
	}
	frameCounter();

}
void Player::updateMovement()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		rect.move(0, -playerSpeed);
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		rect.move(0, playerSpeed);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rect.move(-playerSpeed, 0);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rect.move(playerSpeed, 0);

}

