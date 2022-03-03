#include "Enemy.h"
#include "SetOriginToCenter.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy()
{
	srand(time(NULL));
	int temp = 1 + rand() % 10;

	if (temp <= 4)
	{
		m_enemyType = m_weak;
	}
	else if (temp > 4 && temp <= 7)
	{
		m_enemyType = m_normal;
	}
	else if (temp > 7)
	{
		m_enemyType = m_strong;
	}

	if (m_enemyType == m_weak)
	{
		m_texture.loadFromFile("Textures/alien1.png");
		m_health = 3;
		m_speed = 225.f;
		m_bulletSpeed = 400.f;
	}
	else if (m_enemyType == m_normal)
	{
		m_texture.loadFromFile("Textures/alien2.png");
		m_health = 6;
		m_speed = 175.f;
		m_bulletSpeed = 400.f;
	}
	else if (m_enemyType == m_strong)
	{
		m_texture.loadFromFile("Textures/alien3.png");
		m_health = 10;
		m_speed = 100.f;
		m_bulletSpeed = 400.f;
	}
	m_sprite.setTexture(m_texture);

	temp = 300 + rand() % 725;


	m_sprite.setPosition(sf::Vector2f(temp, -200));
	SetOriginToCenter(m_sprite);
}

Enemy::~Enemy()
{
	
}

EnemyType Enemy::getEnemyType()
{
	return m_enemyType;
}

int Enemy::getHealth()
{
	return m_health;
}

bool Enemy::isHit(Bullet &_bullet)
{
	if (_bullet.getSprite().getGlobalBounds().intersects(m_sprite.getGlobalBounds()) && _bullet.getDirection() != m_down)
	{
		m_health -= 1;
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::move(sf::Time _deltaTime)
{
	m_sprite.move(0, m_speed * _deltaTime.asSeconds());
}

void Enemy::setHealth(int _health)
{
	m_health = _health;
}

std::vector<Bullet*> Enemy::shoot()
{
	std::vector<Bullet*> createdBullets;
	if (this->m_enemyType == m_weak)
	{
		Bullet* bullet = new Bullet(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		createdBullets.push_back(bullet);
	}
	else if (this->m_enemyType == m_normal)
	{
		Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x - 30, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x + 30, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		createdBullets.push_back(bullet1);
		createdBullets.push_back(bullet2);
	}
	else if (this->m_enemyType == m_strong)
	{
		Bullet* bullet1 = new Bullet(sf::Vector2f(m_sprite.getPosition().x-50, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		Bullet* bullet2 = new Bullet(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		Bullet* bullet3 = new Bullet(sf::Vector2f(m_sprite.getPosition().x+50, m_sprite.getPosition().y + 60), m_down, m_bulletSpeed);
		createdBullets.push_back(bullet1);
		createdBullets.push_back(bullet2);
		createdBullets.push_back(bullet3);
	}
	return createdBullets;
}