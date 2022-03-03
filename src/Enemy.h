#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "GameObject.h"

enum EnemyType
{
	m_weak, m_normal, m_strong
};

class Enemy : public GameObject
{
	public:
		Enemy();
		~Enemy();
		EnemyType getEnemyType();
		int getHealth();
		bool isHit(Bullet &_bullet);
		void move(sf::Time _deltaTime);
		void setHealth(int _health);
		std::vector<Bullet*> shoot();

	private:
		int m_health;
		float m_bulletSpeed;
		EnemyType m_enemyType;
};

#endif