#include "Interface.h"
#include "SetOriginToCenter.h"
#include <iostream>

Interface::Interface(sf::Font &_font)
{
	sf::Text temp("0", _font, 60);
	temp.setOutlineThickness(4.f);
	sf::FloatRect boundsRect;

	SetOriginToCenter(temp);
	temp.setPosition(sf::Vector2f(1130, 72));

	m_scoreText = temp;
	m_score = m_scoreText.getString();
	m_scoreValue = std::stoi(m_score);

	m_health.setSize(sf::Vector2f(128, 720));
	boundsRect = m_health.getLocalBounds();
	m_health.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.height);
	m_health.setPosition(sf::Vector2f(96, 90));
	m_health.rotate(180);
	m_health.setFillColor(sf::Color(255, 0, 0, 255));

	m_power.setSize(sf::Vector2f(72, 144));
	boundsRect = m_power.getLocalBounds();
	m_power.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.height);
	m_power.setPosition(sf::Vector2f(1140, 750));
	m_power.rotate(180);


	m_power.setFillColor(sf::Color(255, 255, 0, 255));

	m_speed.setSize(sf::Vector2f(72, 144));
	boundsRect = m_speed.getLocalBounds();
	m_speed.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.height);
	m_speed.setPosition(sf::Vector2f(1228, 750));
	m_speed.rotate(180);


	m_speed.setFillColor(sf::Color(0, 255, 255));

	sf::Texture tempTex;
	tempTex.loadFromFile("Textures/health.png");
	m_healthTexture = tempTex;
	tempTex.loadFromFile("Textures/power.png");
	m_powerTexture = tempTex;
	tempTex.loadFromFile("Textures/speed.png");
	m_speedTexture = tempTex;
	
	m_healthSprite.setTexture(m_healthTexture);
	SetOriginToCenter(m_healthSprite);
	
	m_healthSprite.setPosition(sf::Vector2f(96, 930));

	m_powerSprite.setTexture(m_powerTexture);
	SetOriginToCenter(m_powerSprite);

	m_powerSprite.setPosition(sf::Vector2f(1140, 930));

	m_speedSprite.setTexture(m_speedTexture);
	SetOriginToCenter(m_speedSprite);

	m_speedSprite.setPosition(sf::Vector2f(1228, 930));
}


Interface::~Interface()
{

}

void Interface::addScore(Enemy &_enemy)
{
	if (_enemy.getEnemyType() == m_weak)
	{
		m_scoreValue += 3000;
	}

	if (_enemy.getEnemyType() == m_normal)
	{
		m_scoreValue += 5000;
	}

	if (_enemy.getEnemyType() == m_strong)
	{
		m_scoreValue += 10000;
	}

	m_score = std::to_string(m_scoreValue);
	m_scoreText.setString(m_score);
}

void Interface::draw(sf::RenderWindow &_window)
{
	_window.draw(m_health);
	_window.draw(m_speed);
	_window.draw(m_power);
	_window.draw(m_healthSprite);
	_window.draw(m_speedSprite);
	_window.draw(m_powerSprite);
	_window.draw(m_scoreText);
}

int Interface::getScore()
{
	return m_scoreValue;
}

void Interface::update(Player &_player)
{
	m_healthValue = _player.getHealth();
	m_powerValue = _player.getPower();
	m_speedValue = _player.getSpeed();

	switch (m_healthValue)
	{
		case 3:
		{
			m_health.setSize(sf::Vector2f(128, 720));
			break;
		}
		case 2:
		{
			m_health.setSize(sf::Vector2f(128, 480));
			break;
		}
		case 1:
		{
			m_health.setSize(sf::Vector2f(128, 240));
			break;
		}
		case 0:
		{
			m_health.setSize(sf::Vector2f(0, 0));
			break;
		}
		default:
		{
			std::cout << "The health bar receives invalid values from _player.\n";
			std::cout << "Check Interface.cpp -> update\n";
			break;
		}
	}

	switch (m_powerValue)
	{
		case 5:
		{
			m_power.setSize(sf::Vector2f(72, 720));
			break;
		}
		case 4:
		{
			m_power.setSize(sf::Vector2f(72, 576));
			break;
		}
		case 3:
		{
			m_power.setSize(sf::Vector2f(72, 432));
			break;
		}
		case 2:
		{
			m_power.setSize(sf::Vector2f(72, 288));
			break;
		}
		case 1:
		{
			m_power.setSize(sf::Vector2f(72, 144));
			break;
		}
		default:
		{
			std::cout << "The power bar receives invalid values from _player.\n";
			std::cout << "Check Interface.cpp -> update\n";
			break;
		}
	}
	int temp = m_speedValue * 10;
	switch (temp)
	{
		case 20:
		{
			m_speed.setSize(sf::Vector2f(72, 720));
			break;
		}
		case 15:
		{
			m_speed.setSize(sf::Vector2f(72, 432));
			break;
		}
		case 10:
		{
			m_speed.setSize(sf::Vector2f(72, 144));
			break;
		}
		default:
		{
			std::cout << "The power bar receives invalid values from _player.\n";
			std::cout << "Check Interface.cpp -> update\n";
			break;
		}
	}
}
