#pragma once
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include "Enemy.h"
#include "Player.h"

class Interface
{
	public:
		Interface(sf::Font &_font);
		~Interface();
		void addScore(Enemy &_enemy);
		void draw(sf::RenderWindow &_window);
		int getScore();
		void update(Player &_player);
	private:
		sf::RectangleShape m_health;
		sf::RectangleShape m_speed;
		sf::RectangleShape m_power;
		sf::Sprite m_healthSprite;
		sf::Sprite m_speedSprite;
		sf::Sprite m_powerSprite;
		sf::Texture m_healthTexture;
		sf::Texture m_speedTexture;
		sf::Texture m_powerTexture;
		sf::Text m_scoreText;
		std::string m_score;
		int m_scoreValue;
		int m_healthValue;
		float m_speedValue;
		int m_powerValue;
};

#endif