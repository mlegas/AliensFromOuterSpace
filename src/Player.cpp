#include "Player.h"
#include "SetOriginToCenter.h"
#include <iostream>

Player::Player(sf::Texture &_texture, sf::Vector2f _position)
{
	m_sprite.setTexture(_texture);
	SetOriginToCenter(m_sprite);
	m_sprite.setPosition(_position);
	m_sprite.scale(0.66, 0.66);

	m_health = 3;
	m_power = 1;
	m_speed = 300.0f;
	m_bulletSpeed = 400.0f;
	m_speedFactor = 1.0f;
}

Player::~Player()
{

}

void Player::move(sf::Time _deltaTime, Direction _direction)
{
	switch (_direction)
	{
		case m_up:
		{
			m_sprite.move(0, -m_speed * m_speedFactor * _deltaTime.asSeconds());
			break;
		}
		case m_down:
		{
			m_sprite.move(0, m_speed * m_speedFactor * _deltaTime.asSeconds());
			break;
		}
		case m_left:
		{
			m_sprite.move(-m_speed * m_speedFactor * _deltaTime.asSeconds(), 0);
			break;
		}
		case m_right:
		{
			m_sprite.move(m_speed * m_speedFactor * _deltaTime.asSeconds(), 0);
			break;
		}
		default:
		{
			std::cout << "Something has gone horribly wrong!\n";
			std::cout << "Check the enums for player.cpp.\n";
			break;
		}
	}
}

int Player::getHealth()
{
	return m_health;
}

int Player::getPower()
{
	return m_power;
}

float Player::getSpeed()
{
	return m_speedFactor;
}

bool Player::isHit(Bullet &_bullet)
{
	if (_bullet.getSprite().getGlobalBounds().intersects(m_sprite.getGlobalBounds()) && _bullet.getDirection() != m_up)
	{
		m_health -= 1;
		if (m_speedFactor != 1.f)
		{
			m_speedFactor -= 0.5;
		}
		if (m_power != 1)
		{
			m_power -= 1;
		}
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<Bullet*> Player::shoot()
{
	std::vector<Bullet*> createdBullets;
	switch (m_power)
	{
		case 1:
		{
			Bullet* bullet = new Bullet(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			createdBullets.push_back(bullet);
			break;
		}
		case 2:
		{
			Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 10, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 10, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			createdBullets.push_back(bullet1);
			createdBullets.push_back(bullet2);
			break;
		}
		case 3:
		{
			Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 20, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet3 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 20, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			createdBullets.push_back(bullet1);
			createdBullets.push_back(bullet2);
			createdBullets.push_back(bullet3);
			break;
		}
	case 4:
		{
			Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 30, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 10, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet3 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 10, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet4 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 30, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			createdBullets.push_back(bullet1);
			createdBullets.push_back(bullet2);
			createdBullets.push_back(bullet3);
			createdBullets.push_back(bullet4);
			break;
		}
		case 5:
		{
			Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 40, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 20, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet3 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 0, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet4 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 20, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			Bullet* bullet5 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 40, m_sprite.getPosition().y - 60), m_up, (m_bulletSpeed * m_speedFactor));
			createdBullets.push_back(bullet1);
			createdBullets.push_back(bullet2);
			createdBullets.push_back(bullet3);
			createdBullets.push_back(bullet4);
			createdBullets.push_back(bullet5);
			break;
		}
	}
	return createdBullets;
}

void Player::setHealth(int _health)
{
	m_health = _health;
}

void Player::setSpeed(float _speed)
{
	m_speedFactor = _speed;
}

void Player::setPower(int _power)
{
	m_power = _power;
}