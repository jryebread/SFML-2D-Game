#include "Enemy.h"



Enemy::Enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setFillColor(sf::Color::Blue);
	sprite.setPosition(600, 600);
	sprite.setTextureRect(sf::IntRect(counterIncrement * 49, 0, 32, 42));
}



void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void Enemy::frameCounter()
{
	if (counterIncrement == 3)
		counterIncrement = 0;
	counterIncrement++;
}

void Enemy::updateAnimation()
{
	direction = generateRandom(4);
	 if (direction == 3) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 49, 32, 52));
		direction = 3;
	}
	else if (direction == 4) {
		sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 48 * 2, 32, 52));
		direction = 4;
	}
	frameCounter();

}
void Enemy::updateMovement()
{
	direction = generateRandom(4);
	if (direction == 1)
		rect.move(0, -speed);

	else if (direction == 2)
		rect.move(0, speed);

	else if (direction == 3)
		rect.move(-speed, 0);

	else if (direction == 4)
		rect.move(speed, 0);

}

