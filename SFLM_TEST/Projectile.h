#pragma once
#include "Entity.h"
#include <vector>

class Projectile : public Entity
{
public:
	Projectile();
	enum Direction;
	void update();
	int m_direction = 0;
private:
	int movementSpeed = 20;
	int attackDamage = 5;
};

