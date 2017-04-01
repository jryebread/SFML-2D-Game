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
	sf::RenderWindow window(sf::VideoMode(510,480), "SFML");
	window.setFramerateLimit(60);
	sf::Clock clock, clock_shoot;
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
		//clock
		sf::Time elapsed1 = clock_shoot.getElapsedTime();


		window.draw(spriteBackground);

		//Projectile Collides with Enemy
		int counter2 = 0;
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{

			counter2 = 0;
			for (e_iter = enemyArray.begin(); e_iter != enemyArray.end(); e_iter++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					projectileArray[counter].destroy = true;
					enemyArray[counter2].hp -= projectileArray[counter].attackDamage; 

					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
				}
				counter2++;
			}

			counter++;
		}

		//Delete dead enemies
		counter = 0;
		for (e_iter = enemyArray.begin(); e_iter != enemyArray.end(); e_iter++)
		{
			if (enemyArray[counter].alive == false)
			{
				std::cout << "Enemy Destroyed!" << std::endl;
				enemyArray.erase(e_iter);
				break;
			}
			counter++;
		}
		//Delete Projectiles
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter].destroy == true)
			{
				projectileArray.erase(iter);
				break;
			}
			counter++;
		}

		// Spawn Enemies
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			//Enemy object
			enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
			enemyArray.push_back(enemy1);
		}

		//Fires Missle (Space Bar)
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (elapsed1.asSeconds() >= 0.5)
			{
				clock_shoot.restart();
				projectile1.rect.setPosition(player1.rect.getPosition().x
					+ player1.rect.getSize().x / 2 - projectile1.rect.getSize().x / 2, player1.rect.getPosition().y + player1.rect.getSize().y / 2 - projectile1.rect.getSize().y / 2);
				projectile1.m_direction = player1.m_direction;
				projectileArray.push_back(projectile1);
			}
		}
		
	
			
		// Draw Projectiles
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
			enemyArray[counter].updateMovement();
			//window.draw(enemyArray[counter].rect);
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
