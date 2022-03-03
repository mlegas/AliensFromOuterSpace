#include "Button.h"
#include "GameOverScreen.h"
#include "SetOriginToCenter.h"
#include <string>

void GameOverScreen(sf::RenderWindow &_window, int _score)
{
	sf::Sprite background;
	sf::Texture btnTexture, lostBackground, wonBackground;
	sf::Font agency;
	lostBackground.loadFromFile("Textures/lostBackground.png");
	wonBackground.loadFromFile("Textures/wonBackground.png");
	agency.loadFromFile("Fonts/agency.ttf");
	btnTexture.loadFromFile("Textures/button.png");

	_window.clear();
	if (_score > 300000)
	{
		background.setTexture(wonBackground);
	}
	else
	{
		background.setTexture(lostBackground);
	}

	std::string scoreText("Score: ");

	scoreText += std::to_string(_score);
	sf::Text score(scoreText, agency, 48);
	SetOriginToCenter(score);

	score.setPosition(sf::Vector2f(640, 275));

	sf::Text buttonText("Quit to Menu", agency, 36);
	Button button(100, btnTexture, buttonText, sf::Vector2f(640, 800));

	std::vector<sf::Text> textList;

	textList.push_back(score);
	textList.push_back(buttonText);

	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_window.close();
			}

			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (button.isClicked(_window))
				{
					return;
				}
			}
			button.isHovered(_window);

			_window.clear();
			_window.draw(background);

			_window.draw(button.getSprite());

			for (int i = 0; i < 2; i++)
			{
				_window.draw(textList[i]);
			}

			_window.display();
		}
	}
}