#include "Button.h"
#include "Menu.h"
#include "GameLoop.h"
#include "SetOriginToCenter.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

int MainMenu(sf::RenderWindow &_window)
{
	sf::Font agency;
	agency.loadFromFile("Fonts/agency.ttf");
	sf::Texture menuBkgTexture, btnTexture;

	btnTexture.loadFromFile("Textures/button.png");
	menuBkgTexture.loadFromFile("Textures/menuBackground.png");
	sf::Sprite background(menuBkgTexture);

	sf::Text title("Aliens from Outer Space!", agency, 78);
	title.setOutlineThickness(8);
	SetOriginToCenter(title);
	title.setPosition(sf::Vector2f(640, 400));

	sf::Text buttonText1("Play", agency, 36);
	sf::Text buttonText2("Instructions", agency, 36);
	sf::Text buttonText3("Quit Game", agency, 36);
	Button button1(1, btnTexture, buttonText1, sf::Vector2f(640, 550));
	Button button2(2, btnTexture, buttonText2, sf::Vector2f(640, 650));
	Button button3(3, btnTexture, buttonText3, sf::Vector2f(640, 750));

	std::vector<Button> buttonList;
	std::vector<sf::Text> textList;

	buttonList.push_back(button1);
	buttonList.push_back(button2);
	buttonList.push_back(button3);

	textList.push_back(title);
	textList.push_back(buttonText1);
	textList.push_back(buttonText2);
	textList.push_back(buttonText3);

	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_window.close();
				return 3;
			}


			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < 3; i++)
				{
					if (buttonList[i].isClicked(_window))
					{
						return buttonList[i].getAction();
					}
				}
			}
		}

			for (int i = 0; i < 3; i++)
			{
				buttonList[i].isHovered(_window);
			}

			_window.clear();
			_window.draw(background);

			for (int i = 0; i < 3; i++)
			{
				_window.draw(buttonList[i].getSprite());
			}

			for (int i = 0; i < 4; i++)
			{
				_window.draw(textList[i]);
			}
			_window.display();

		}
	}