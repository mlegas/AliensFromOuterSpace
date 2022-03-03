#include "Button.h"
#include "SetOriginToCenter.h"

Button::Button(int _action, sf::Texture &_texture, sf::Text &_text, sf::Vector2f _position)
{
	m_action = _action;

	SetOriginToCenter(_text);
	
	sf::Sprite button(_texture);
	SetOriginToCenter(button);
	
	button.setPosition(_position);
	_text.setPosition(_position);
	
	m_sprite = button;
}

Button::~Button()
{

}

int Button::getAction()
{
	return m_action;
}

sf::Sprite Button::getSprite()
{
	return m_sprite;
}

bool Button::isClicked(sf::RenderWindow &_window)
{
	if (m_sprite.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
	{
		return true;	
	}
	else
	{
		return false;
	}
}

void Button::isHovered(sf::RenderWindow &_window)
{
	if (m_sprite.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
	{
		m_sprite.setColor(sf::Color(255, 255, 255, 128));
	}
	else
	{
		m_sprite.setColor(sf::Color(255, 255, 255, 200));
	}
}