#include "Projectile.h"




Projectile::Projectile()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setFillColor(sf::Color::Green);
	sprite.setPosition(0, 0);
	//sprite.setTextureRect(sf::IntRect(counterIncrement * 32, 0, 32, 52));
}

void Projectile::update()
{
	if (m_direction == 1)
	{
		rect.move(0, -movementSpeed);
	}
	else if (m_direction == 2)
	{
		rect.move(0, movementSpeed);
	}
	else if (m_direction == 3)
	{
		rect.move(-movementSpeed, 0);
	}
	else if (m_direction == 4)
	{
		rect.move(movementSpeed, 0);
	}
	
}
