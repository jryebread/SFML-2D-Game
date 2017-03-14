#include "Enemy.h"



Enemy::Enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setFillColor(sf::Color::Blue);
	sprite.setPosition(600, 600);
	sprite.setTextureRect(sf::IntRect(4* 49, -2, 49, 49));
}



void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void Enemy::frameCounter()
{
	if (frameIncrement == 1)
		frameIncrement = 0;
	++frameIncrement;
}

/*void Enemy::updateAnimation()
{
	direction = generateRandom(4);
	 if (direction == 3) {
		sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * frameIncrement, 100, 59, 49));
	}
	else if (direction == 4) {
		sprite.setTextureRect(sf::IntRect((49 * 6) + 9 * frameIncrement, 10, 59, 49));
		
	}

}*/
void Enemy::updateMovement()
{
	if (direction == 1)
		rect.move(0, -speed);
		
	else if (direction == 2)
		rect.move(0, speed);

	else if (direction == 3)
	{
	sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * frameIncrement, -2, 49, 49));
	rect.move(-speed, 0);
	}

	else if (direction == 4) 
	{
	rect.move(speed, 0);
	sprite.setTextureRect(sf::IntRect((49 * 6) + 49 * frameIncrement, -2, 49, 49));
	}
	else
	{
		//no movement
	}	

	counter++;
		if (counter >= movementLength) //generate a new direction for ai
		{
			direction = generateRandom(5);
			counter = 0; //reset counter
		}

	frameCounter();
}

