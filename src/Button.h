#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
	public:
		Button(int _action, sf::Texture &_texture, sf::Text &_text, sf::Vector2f _position);
		~Button();
		int getAction();
		sf::Sprite getSprite();
		bool isClicked(sf::RenderWindow &_window);
		void isHovered(sf::RenderWindow &_window);

	private:
		int m_action;
		sf::Sprite m_sprite;
};

#endif