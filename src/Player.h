#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp> 
#include "Bullet.h"
#include "GameObject.h"

class Player : public GameObject
{
	public:
		Player(sf::Texture &_texture, sf::Vector2f _position);
		~Player();
		void move(sf::Time _deltaTime, Direction _direction);
		std::vector<Bullet*> shoot();
		int getHealth();
		int getPower();
		float getSpeed();
		bool isHit(Bullet &_bullet);
		void setHealth(int _health);
		void setPower(int _power);
		void setSpeed(float _speed);

	private:
		int m_health;
		int m_power;
		float m_bulletSpeed;
		float m_speedFactor;
};

#endif