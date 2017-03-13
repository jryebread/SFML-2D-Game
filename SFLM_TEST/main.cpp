#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"
#include "Player.h"
#include "Entity.h"
#include <vector>
#include "Projectile.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(510,480), "SFML works!");
	window.setFramerateLimit(60);
	sf::Clock clock;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 600;
	int counter = 0;
	//sf::Texture textureShip;
	//if (!textureShip.loadFromFile("ship.png")) {
	//	return EXIT_FAILURE;
	//}
	/*sf::Sprite spriteShip(textureShip);
	spriteShip.setPosition(0, 0);*/
	//spriteShip.setColor(sf::Color::Blue);
	/////////////////////////
	sf::Font font;
	if (!font.loadFromFile("wargames.ttf")) {
		return EXIT_FAILURE;
	}
	sf::Text text("SFML", font, 25);
	text.setCharacterSize(45);
	text.setPosition(0,0);
	///////////PlayerWalkSprite//////////////
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("sprite.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite spritePlayer(texturePlayer);
	Player player1;
	player1.sprite.setTexture(texturePlayer);

	/////////////EnemySprite///////////////
	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile("enemySprite.png")) {
		return EXIT_FAILURE;
	}
	Enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	//////////////////////Background////////////////////////
	sf::Texture textureBackground;
	if (!textureBackground.loadFromFile("background.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite spriteBackground(textureBackground);

	

	//Projectile Array
	Projectile projectile1;
	std::vector<Projectile>::const_iterator iter;
	std::vector<Projectile> projectileArray;

	
	
	//Enemy Vector Array
	std::vector<Enemy>::const_iterator e_iter;
	std::vector<Enemy> enemyArray;
	//Enemy object
	enemy1.rect.setPosition(300, 200);
	enemyArray.push_back(enemy1);
	
	

	sf::Event event;

	//Game Loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Clear Screen
		window.clear();
		window.draw(spriteBackground);
		
		// Draw Projectiles
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2 - projectile1.rect.getSize().x/2, player1.rect.getPosition().y + player1.rect.getSize().y / 2 - projectile1.rect.getSize().y/2);
				projectile1.m_direction = player1.m_direction;
				projectileArray.push_back(projectile1);
			}
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				projectileArray[counter].update(); //update projectiles
				window.draw(projectileArray[counter].rect);
				counter++;
			}

			
			//Draw Enemies
			counter = 0;
			for (e_iter = enemyArray.begin(); e_iter != enemyArray.end(); e_iter++)
			{
				enemyArray[counter].update(); 
				window.draw(enemyArray[counter].rect);
				window.draw(enemyArray[counter].sprite);
				counter++;
			}
		

		
		player1.update();

		//Animation Delay and update
	
		frameCounter += frameSpeed  * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
		player1.updateAnimation();
		frameCounter = 0;
		}
		player1.updateMovement();
		//Draw the sprite
		window.draw(player1.sprite);
		
		//Update the window
		window.display();
	}
	
	return 0;
}
