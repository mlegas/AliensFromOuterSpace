#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <SFML/Graphics.hpp>

enum Direction
{
	m_left, m_right, m_up, m_down
};

class GameObject
{
	public:
	sf::Sprite getSprite();
	sf::Texture getTexture();
	protected:
		sf::Sprite m_sprite;
		sf::Texture m_texture;
		float m_speed;
};

#endif