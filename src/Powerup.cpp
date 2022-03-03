#include "Powerup.h"
#include "SetOriginToCenter.h"
#include <ctime>
#include <cstdlib>

Powerup::Powerup(sf::Vector2f _position, Player &_player)
{
	m_pickedUp = false;

	srand(time(NULL));
	int random = 1 + rand() % 10;

	if (_player.getHealth() < 2)
	{
		if (random <= 2)
		{
			m_powerupType = m_power;
			m_texture.loadFromFile("Textures/power.png");
		}
		else if (random > 2 && random <= 8)
		{
			m_powerupType = m_health;
			m_texture.loadFromFile("Textures/health.png");
		}
		else if (random > 8)
		{
			m_powerupType = m_haste;
			m_texture.loadFromFile("Textures/speed.png");
		}
	}
	else
	{
		if (random <= 4)
		{
			m_powerupType = m_power;
			m_texture.loadFromFile("Textures/power.png");
		}
		else if (random > 4 && random <= 7)
		{
			m_powerupType = m_health;
			m_texture.loadFromFile("Textures/health.png");
		}
		else if (random > 7)
		{
			m_powerupType = m_haste;
			m_texture.loadFromFile("Textures/speed.png");
		}
	}

	m_sprite.setTexture(m_texture);

	SetOriginToCenter(m_sprite);

	m_sprite.setPosition(_position);

	m_speed = 100;
}

Powerup::~Powerup()
{

}

void Powerup::move(sf::Time _deltaTime)
{
	m_sprite.move(0, m_speed * _deltaTime.asSeconds());
}

bool Powerup::isPickedUp(Player &_player)
{
	if (m_sprite.getGlobalBounds().intersects(_player.getSprite().getGlobalBounds()) && !m_pickedUp)
	{
		if (m_powerupType == m_health && _player.getHealth() < 3)
		{
			_player.setHealth(_player.getHealth() + 1);
		}
		else if (m_powerupType == m_power && _player.getPower() < 5)
		{
			_player.setPower(_player.getPower() + 1);
		}
		else if (m_powerupType == m_haste && _player.getSpeed() < 2)
		{
			_player.setSpeed(_player.getSpeed() + 0.5);
		}
		m_pickedUp = true;
		return true;
	}
	else
	{
		return false;
	}
}