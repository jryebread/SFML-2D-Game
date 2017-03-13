#pragma once
#include "Entity.h"
#include "random.h"
class Enemy :public Entity
{
public:
	Enemy();
	void update();
	void updateMovement();
	void updateAnimation();
	void frameCounter();
	int direction = 0;
private:
	int counterIncrement = 5;
	int speed = 2;
	int attackDamage = 5;

};

