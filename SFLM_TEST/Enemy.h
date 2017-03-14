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
	int counter = 0;
	int frameIncrement = 0;
	int speed = 2;
	int movementLength = 30;
	int attackDamage = 5;

};

