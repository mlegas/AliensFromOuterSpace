#include "BackgroundSparkle.h"

BackgroundSparkle::BackgroundSparkle(sf::Vector2f _position)
{
	m_shape.setPosition(_position);
	m_shape.setRadius(5.f);
	m_shape.setFillColor(sf::Color(255, 255, 255, 194));
	m_speed =	150.f;
}

BackgroundSparkle::~BackgroundSparkle()
{

}

void BackgroundSparkle::setPosition(sf::Vector2f _position)
{
	m_shape.setPosition(_position);
}

sf::Vector2f BackgroundSparkle::getPosition()
{
	return m_shape.getPosition();
}

sf::CircleShape BackgroundSparkle::getShape()
{
	return m_shape;
}

void BackgroundSparkle::move(sf::Time _deltaTime)
{
	m_shape.move(0, m_speed * _deltaTime.asSeconds());
}