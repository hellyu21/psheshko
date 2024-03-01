#pragma once
#include <string>
#include <thread>

namespace lu
{

	const float pi = acos(-1);

	class Gra
	{
		int l_width;
		int l_height;
		std::string l_capture;
		lu::Circle l_c;
		sf::RenderWindow l_window;

	public:
		Gra(int width, int height, const std::string& capture)
		{
			l_width = width;
			l_height = height;
			l_capture = capture;
		}

		void Setup()
		{
			l_window.create(sf::VideoMode(l_width, l_height), l_capture);

			srand(time(0));

			int r = 20;
			int x = rand() % (1000 - 2 * r) + r;
			int y = rand() % (600 - 2 * r) + r;
			int v = rand() % 50 + 10;
			int alfa = pi;
			l_c.Setup(x, y, r, v, alfa);
		}

		void TouchBorder(Circle& obj)
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= l_width || x - r <= 0)
			{
				obj.Alfa(pi - obj.Alfa());
			}

			if (y + r >= l_height || y - r <= 0)
			{
				obj.Alfa(2 * pi - obj.Alfa());
			}

		}

		void LifeCycle()
		{
			sf::Clock clock;

			while (l_window.isOpen())
			{

				sf::Event event;
				while (l_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						l_window.close();
				}

				//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();


				l_c.Move(dt);

				TouchBorder(l_c);


				l_window.clear();
				l_window.draw(l_c.Get());
				l_window.display();
			}
		}
	};

}