#pragma once
#include "Entity.h"
#include <vector>

class Projectile : public Entity
{
public:
	Projectile();
	void update();
	int m_direction = 0;
private:
	int movementSpeed = 10;
	int attackDamage = 5;
};

