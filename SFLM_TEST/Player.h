#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Player : public Entity
{
public:
	Player();
	void update();
	void updateMovement();
	void updateAnimation();
	void frameCounter();
	int m_direction = 1;
	

private:
	int counterIncrement = 0;
	int playerSpeed = 2;
	int attackDamage = 5;

};

