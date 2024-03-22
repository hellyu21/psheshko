#pragma once
#include <string>
#include <thread>
#include <text.hpp>
#include <iostream>
using namespace std;

namespace lu
{

	class Gra
	{
		int width;
		int height;
		int lenght = 1;
		float showtime = 24.;
		string capture;
		string text = "Hi, bitches!";
		sf::Text Mess;
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
			Mess.setColor(sf::Color::White);
			Mess.setFont(font);

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
				Mess.setString(text.substr(0, lenght));
				if (lenght < text.size())
					lenght += 1;
				float dt = clock.getElapsedTime().asSeconds();
				if (showtime/text.size() > dt)
				{
					sf::Time t = sf::seconds(showtime/ text.size()-dt);
					sf::sleep(t);
				}
				clock.restart();

				if (!font.loadFromFile("tools\\arial.ttf"))
				{
					std::cout << "Error while loading arial.ttf" << std::endl;
				}
				
				window.clear();
				window.draw(Mess);
				window.display();
			}
		}
	};

}