#include "Bullet.h"
#include "SetOriginToCenter.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f _position, Direction _direction, float _speed)
{
	m_speed = _speed;
	m_direction = _direction;

	if (_direction == m_up)
	{
		m_texture.loadFromFile("Textures/bullet.png");
	}
	else if (_direction == m_down)
	{
		m_texture.loadFromFile("Textures/enemyBullet.png");
	}

	sf::Sprite temp(m_texture);
	SetOriginToCenter(temp);
	
	temp.setPosition(_position);

	m_sprite = temp;
}

Bullet::~Bullet()
{
}

Direction Bullet::getDirection()
{
	return m_direction;
}

void Bullet::move(sf::Time _deltaTime)
{
	if (m_direction == m_up)
	{
		m_sprite.move(0, -m_speed * _deltaTime.asSeconds());
	}

	else if (m_direction == m_down)
	{
		m_sprite.move(0, m_speed * _deltaTime.asSeconds());
	}
	
	else
	{
		std::cout << "Something has gone horribly wrong!\n";
		std::cout << "Check bullet::move in bullet.cpp\n";
	}
}
