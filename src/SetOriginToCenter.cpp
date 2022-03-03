#include "SetOriginToCenter.h"

void SetOriginToCenter(sf::Sprite &_sprite)
{
	sf::FloatRect boundsRect = _sprite.getLocalBounds();
	_sprite.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.top + boundsRect.height / 2.0f);
}

void SetOriginToCenter(sf::Text &_text)
{
	sf::FloatRect boundsRect = _text.getLocalBounds();
	_text.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.top + boundsRect.height / 2.0f);
}

void SetOriginToCenter(sf::RectangleShape &_shape)
{
	sf::FloatRect boundsRect = _shape.getLocalBounds();
	_shape.setOrigin(boundsRect.left + boundsRect.width / 2.0f, boundsRect.top + boundsRect.height / 2.0f);
}