#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Bullet : public GameObject
{
	public:
		Bullet(sf::Vector2f _position, Direction _direction, float _speed);
		~Bullet();
		Direction getDirection();
		void move(sf::Time _deltaTime);

	private:
		sf::Vector2f m_position;
		Direction m_direction;
};

#endif