#pragma once
#include <string>
#include <thread>
#include <text.hpp>
#include <iostream>

namespace lu
{

	class Gra
	{
		int width;
		int height;
		std::string capture;
		lu::mytext text;
		sf::Font font;
		sf::RenderWindow window;

	public:
		Gra(int gotwidth, int gotheight)
		{
			width = gotwidth;
			height = gotheight;
		}

		void Setup()
		{
			window.create(sf::VideoMode(width, height), "Text");
			mytext("Hi, bitches!");

		}


		void LifeCycle()
		{
			sf::Clock clock;

			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				if (!font.loadFromFile("arial.ttf"))
				{
					std::cout << "Error while loading arial.ttf" << std::endl;
				}
				
				window.clear();
				window.draw(text);
				window.display();
			}
		}
	};

}