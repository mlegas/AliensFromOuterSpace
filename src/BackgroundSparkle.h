#pragma once
#ifndef _BACKGROUNDSPARKLE_H_
#define _BACKGROUNDSPARKLE_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class BackgroundSparkle : public GameObject
{
	public:
		BackgroundSparkle(sf::Vector2f _position);
		~BackgroundSparkle();
		void move(sf::Time _deltaTime);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f _position);
		sf::CircleShape getShape();
		
	private:
		sf::CircleShape m_shape;
};

#endif