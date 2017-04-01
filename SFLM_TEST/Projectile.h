#pragma once
#include "Entity.h"
#include <vector>

class Projectile : public Entity
{
public:
	Projectile();
	void update();
	int m_direction = 0;
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 100;
	int attackDamage = 1;
private:
	int movementSpeed = 15;
};

