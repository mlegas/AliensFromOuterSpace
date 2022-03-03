#include "GameLoop.h"
#include "BackgroundSparkle.h"
#include "Player.h"
#include "Enemy.h"
#include "Interface.h"
#include "GameOverScreen.h"
#include "Powerup.h"
#include "Explosion.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>

void GameLoop(sf::RenderWindow &_window)
{
	srand(time(NULL));
	sf::Clock deltaTimeClock;
	sf::Clock playerShootTimer;
	sf::Clock enemyShootTimer;
	sf::Clock enemySpawnTimer;
	sf::SoundBuffer fireBuffer, powerupBuffer, hitBuffer, explosionBuffer;
	fireBuffer.loadFromFile("Sounds/fire.wav");
	sf::Sound fire1, fire2, powerup, hit1, hit2, explosion;
	fire1.setBuffer(fireBuffer);
	fire2.setBuffer(fireBuffer);

	powerupBuffer.loadFromFile("Sounds/powerup.wav");
	powerup.setBuffer(powerupBuffer);

	hitBuffer.loadFromFile("Sounds/hit.flac");
	hit1.setBuffer(hitBuffer);
	hit2.setBuffer(hitBuffer);

	explosionBuffer.loadFromFile("Sounds/explosion.wav");
	explosion.setBuffer(explosionBuffer);

	sf::Music gameMusic;
	gameMusic.openFromFile("Music/gameMusic.ogg");

	gameMusic.play();
	gameMusic.setLoop(true);

	bool quitGame = false;
	bool gameOver = false;
	bool repeatGame = false;

	int endScore;

	sf::Font agency;
	agency.loadFromFile("Fonts/agency.ttf");

	sf::FloatRect boundaries(sf::Vector2f(0, 0), sf::Vector2f(1280, 930));

	int eventTimer = 0;

	sf::Time deltaTime = sf::seconds(1.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/player.png");

	sf::Texture gameBkgTexture;
	gameBkgTexture.loadFromFile("Textures/gameBackground.jpg");

	sf::Sprite gameBackground(gameBkgTexture);
	gameBackground.setColor(sf::Color(255, 255, 255, 128));

	Interface hud(agency);
	Player *player = new Player(playerTexture, sf::Vector2f(640, 867));

	sf::Texture columnTexture;
	columnTexture.loadFromFile("Textures/column.png");

	sf::Sprite column1(columnTexture);
	sf::Sprite column2(columnTexture);

	column2.setPosition(sf::Vector2f(1088, 0));

	std::vector<BackgroundSparkle> sparkles;
	std::vector<Bullet*> enemyBullets;
	std::vector<Bullet*> playerBullets;
	std::vector<Enemy*> enemies;
	std::vector<Powerup*> powerups;
	std::vector<Explosion*> explosions;

	while (!quitGame)
	{
		for (int i = 0; i < 70; i++)
		{
			int tempx = rand() % 866 + 212;
			int tempy = rand() % 960;
			BackgroundSparkle temp(sf::Vector2f(tempx, tempy));
			sparkles.push_back(temp);
		}

		while (_window.isOpen() && !gameOver)
		{
			sf::Event event;

			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_window.close();
					return;
				}
			}

			_window.clear();
			_window.draw(gameBackground);

			for (std::vector<BackgroundSparkle>::iterator itr = sparkles.begin(); itr != sparkles.end(); itr++)
			{
				if ((*itr).getPosition().y > 960)
				{
					sf::Vector2f temp = (*itr).getPosition();
					temp.x += (rand() % 40) - 20;
					temp.y = -12;
					temp.y += (rand() % 3) - 2;
					(*itr).setPosition(temp);
				}
				_window.draw((*itr).getShape());
				(*itr).move(deltaTime);
			}

			_window.draw(column1);
			_window.draw(column2);
			hud.update(*player);
			hud.draw(_window);

			_window.draw(player->getSprite());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !player->getSprite().getGlobalBounds().intersects(column1.getGlobalBounds()))
			{
				player->move(deltaTime, m_left);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !player->getSprite().getGlobalBounds().intersects(column2.getGlobalBounds()))
			{
				player->move(deltaTime, m_right);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player->getSprite().getGlobalBounds().top > (_window.getSize().y - 600))
			{
				player->move(deltaTime, m_up);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player->getSprite().getGlobalBounds().intersects(boundaries))
			{
				player->move(deltaTime, m_down);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (playerBullets.size() < (int)(10 * player->getPower()) && !(playerShootTimer.asSeconds() >= (10.0f / player->getSpeed())))
				{
					fire1.play();
					std::vector<Bullet*> shotBullets = player->shoot();
					playerBullets.insert(playerBullets.end(), shotBullets.begin(), shotBullets.end());
					playerShootTimer.restart();
				}
			}

			std::vector<Enemy*>::iterator enmitr = enemies.begin();
			std::vector<Bullet*>::iterator pbltitr = playerBullets.begin();

			for (enmitr; enmitr != enemies.end();)
			{
				pbltitr = playerBullets.begin();
				for (pbltitr; pbltitr != playerBullets.end();)
				{
					if ((**enmitr).isHit(**pbltitr))
					{
						hit1.play();
						delete *pbltitr;
						pbltitr = playerBullets.erase(pbltitr);
					}
					else
					{
						pbltitr++;
					}
				}

				if ((**enmitr).getSprite().getPosition().y-20 > _window.getSize().y)
				{
					delete *enmitr;
					enmitr = enemies.erase(enmitr);
				}

				else if ((**enmitr).getSprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
				{
					explosion.play();
					player->setHealth(0);
					(**enmitr).setHealth(0);
					delete *enmitr;
					enmitr = enemies.erase(enmitr);
				}

				else if ((**enmitr).getHealth() <= 0)
				{
					explosion.play();
					explosions.push_back(new Explosion((**enmitr).getSprite().getPosition()));
					hud.addScore(**enmitr);
					int random = 1 + rand() % 10;
					if (random <= 3)
					{
						powerups.push_back(new Powerup((**enmitr).getSprite().getPosition(), *(player)));
					}
					delete *enmitr;
					enmitr = enemies.erase(enmitr);
				}

				else
				{
					_window.draw((**enmitr).getSprite());
					(**enmitr).move(deltaTime);

					if (!(enemyShootTimer.asSeconds() >= 2.5f))
					{
						fire2.play();
						std::vector<Bullet*> enemyShotBullets = (**enmitr).shoot();
						enemyBullets.insert(enemyBullets.end(), enemyShotBullets.begin(), enemyShotBullets.end());
					}
					enmitr++;
				}
			}

			if (enemyShootTimer.asSeconds() >= 2.5f)
			{
				enemyShootTimer.restart();
			}

			pbltitr = playerBullets.begin();

			for (pbltitr; pbltitr != playerBullets.end();)
			{
				if ((**pbltitr).getSprite().getPosition().y < 0)
				{
					delete *pbltitr;
					pbltitr = playerBullets.erase(pbltitr);
				}
				else
				{
					_window.draw((**pbltitr).getSprite());
					(**pbltitr).move(deltaTime);
					pbltitr++;

				}
			}

			if (enemySpawnTimer.asSeconds() >= 4.5f)
			{
				enemies.push_back(new Enemy);
				enemySpawnTimer.restart();
			}

			if (eventTimer == INT_MAX)
			{
				eventTimer = 0;
			}

			std::vector<Bullet*>::iterator ebltitr = enemyBullets.begin();

			for (ebltitr; ebltitr != enemyBullets.end();)
			{
				if ((**ebltitr).getSprite().getPosition().y > _window.getSize().y)
				{
					delete *ebltitr;
					ebltitr = enemyBullets.erase(ebltitr);
				}
				else
				{
					_window.draw((**ebltitr).getSprite());
					(**ebltitr).move(deltaTime);
					if (player->isHit(**ebltitr))
					{
						hit2.play();
						delete *ebltitr;
						ebltitr = enemyBullets.erase(ebltitr);
					}
					else
					{
						ebltitr++;
					}
				}
			}

			std::vector<Powerup*>::iterator pwrupitr = powerups.begin();
			for (pwrupitr; pwrupitr != powerups.end();)
			{
				if ((**pwrupitr).isPickedUp(*player))
				{
					powerup.play();
					delete *pwrupitr;
					pwrupitr = powerups.erase(pwrupitr);
				}
				else
				{
					_window.draw((**pwrupitr).getSprite());
					(**pwrupitr).move(deltaTime);
					pwrupitr++;
				}
			}

			std::vector<Explosion*>::iterator explitr = explosions.begin();
			for (explitr; explitr != explosions.end();)
			{
				if (!(**explitr).update(eventTimer))
				{
					delete *explitr;
					explitr = explosions.erase(explitr);
				}
				else
				{
					_window.draw((**explitr).getSprite());
					explitr++;
				}
			}

			deltaTime = deltaTimeClock.restart();
			eventTimer++;
			_window.display();


			if (player->getHealth() <= 0 || hud.getScore() > 300000)
			{
				gameOver = true;
				endScore = hud.getScore();
			}
		}

		gameMusic.stop();
		GameOverScreen(_window, endScore);
		quitGame = true;

	}

	delete player;
	sparkles.clear();
	enemyBullets.clear();
	playerBullets.clear();
	enemies.clear();
	powerups.clear();

}