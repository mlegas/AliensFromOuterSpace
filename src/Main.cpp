#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Instructions.h"
#include "Menu.h"
#include "GameLoop.h"

int main()
{
	int choice;
	bool quitGame = false;

	sf::Music intro;
	intro.openFromFile("Music/intro.ogg");

	intro.play();
	intro.setLoop(true);

	sf::RenderWindow window(sf::VideoMode(1280, 960), "Aliens From Outer Space!");
	window.setPosition(sf::Vector2i(310, 10));
	while (window.isOpen() && !quitGame)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
		}
		choice = MainMenu(window);
		switch (choice)
		{
			case 1:
			{
				intro.stop();
				GameLoop(window);
				intro.play();
				break;
			}
			case 2:
			{
				Instructions(window);
				break;
			}
			case 3:
			{
				intro.stop();
				quitGame = true;
				break;
			}
		}
	}
	if (window.isOpen())
	{
		window.close();
	}
	return 0;
}