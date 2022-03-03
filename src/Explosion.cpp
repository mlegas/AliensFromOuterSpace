#include "Explosion.h"
#include "SetOriginToCenter.h"

Explosion::Explosion(sf::Vector2f _position)
{
	m_texture.loadFromFile("Textures/explosion.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 640, 128, 128));
	m_sprite.scale(2, 2);
	m_sprite.setPosition(_position);
	SetOriginToCenter(m_sprite);
	m_frame = 1;
}

Explosion::~Explosion()
{

}

bool Explosion::update(int _timer)
{
	if (m_frame <= 5 && !(_timer % 40))
	{
		m_frame++;
		m_sprite.setTextureRect(sf::IntRect(m_frame * 128, 0, 128, 128));
		return true;
	}
	else if (m_frame <= 5)
	{
		m_sprite.setTextureRect(sf::IntRect(m_frame * 128, 0, 128, 128));
		return true;
	}
	else
	{
		return false;
	}
}