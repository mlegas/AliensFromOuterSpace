#pragma once
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Explosion : public GameObject
{
	public:
		Explosion(sf::Vector2f _position);
		~Explosion();
		bool update(int _timer);

	private:
		int m_frame;
		sf::IntRect m_textureRect;
};

#endif