#include "Button.h"
#include "Instructions.h"
#include "SetOriginToCenter.h"

void Instructions(sf::RenderWindow &_window)
{
	sf::Font agency;
	agency.loadFromFile("Fonts/agency.ttf");
	sf::Text exitText("Exit to Menu", agency, 36);

	SetOriginToCenter(exitText);
	exitText.setPosition(sf::Vector2f(525, 880));

	sf::Texture btnTexture;
	btnTexture.loadFromFile("Textures/button.png");

	Button exitToMenu(0, btnTexture, exitText, sf::Vector2f(640, 800));
	
	sf::Texture menuBkgTexture;
	menuBkgTexture.loadFromFile("Textures/menuBackground.png");
	sf::Sprite background(menuBkgTexture);

	sf::Texture instructionsTexture;
	instructionsTexture.loadFromFile("Textures/instructions.png");
	sf::Sprite instructionsSprite(instructionsTexture);
	
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_window.close();
			}
			else if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (exitToMenu.isClicked(_window))
				{
					return;
				}
			}

			exitToMenu.isHovered(_window);

			_window.clear();
			_window.draw(background);
			_window.draw(instructionsSprite);
			_window.draw(exitToMenu.getSprite());
			_window.draw(exitText);
			_window.display();
		}
	}
}
