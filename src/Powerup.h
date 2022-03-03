#pragma once
#ifndef _POWERUP_H_
#define _POWERUP_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

enum PowerupType
{
	m_health, m_power, m_haste
};

class Powerup : public GameObject
{
	public:
		Powerup(sf::Vector2f _position, Player &_player);
		~Powerup();
		bool isPickedUp(Player &_player);
		void move(sf::Time _deltaTime);
	private:
		PowerupType m_powerupType;
		bool m_pickedUp;
};

#endif
