#include "Projectile.h"




Projectile::Projectile()
{
	rect.setSize(sf::Vector2f(15, 15));
	rect.setFillColor(sf::Color::Red);
	sprite.setPosition(0, 0);
	
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
	counterLifetime++;
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}
}
