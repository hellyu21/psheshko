#pragma once
#include <string>
#include <thread>

namespace lu
{

	class Gra
	{
		int l_width;
		int l_height;
		std::string l_capture;
		lu::Circle l_c;
		lu::Rect l_rect;
		lu::Poly l_p;
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

			l_c.Setup(200, 66, 60, 400);
			l_rect.Setup(500, 25, 100, 40, 300);
			l_p.Setup(800, 100, 80, 6, 100);
		}

		void TouchBorder(Circle& obj, float dt)
		{
			float y = obj.Y();
			float r = obj.R();
			float v = obj.V();

			if (y + v*dt + r >= l_height)
			{
				obj.Move((l_height - y - r) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (l_height - y - r) / v);
			}
			else if (y + v * dt - r <= 0)
			{
				obj.Move((y - r) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (y - r) / v);
			}
			else {
				obj.Move(dt);
			}

		}

		void TouchBorder(Rect& obj, float dt)
		{
			float y = obj.Y();
			float b = obj.B();
			float v = obj.V();

			if (y + v * dt + b/2 >= l_height)
			{
				obj.Move((l_height - y - b/2) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (l_height - y - b/2) / v);
			}
			else if (y + v * dt - b/2 <= 0)
			{
				obj.Move((y - b/2) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (y - b/2) / v);
			}
			else {
				obj.Move(dt);
			}

		}

		void TouchBorder(Poly& obj, float dt)
		{
			float y = obj.Y();
			float a = obj.A();
			float v = obj.V();

			if (y + v * dt + a >= l_height)
			{
				obj.Move((l_height - y - a) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (l_height - y - a) / v);
			}
			else if (y + v * dt - a <= 0)
			{
				obj.Move((y - a) / v);
				obj.ReverseSpeed();
				obj.ChangeColor();
				obj.Move(dt - (y - a) / v);
			}
			else {
				obj.Move(dt);
			}

		}

		void LifeCycle()
		{
			sf::Clock clock;
			float time = 0;

			while (l_window.isOpen())
			{

				sf::Event event;
				while (l_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						l_window.close();
				}

				//std::this_thread::sleep_for(std::chrono::milliseconds(500));

				
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();
				time += dt;

				if (time > 3)
				{
					TouchBorder(l_c, dt);
					TouchBorder(l_rect, dt);
					TouchBorder(l_p, dt);
				}


				l_window.clear();
				l_window.draw(l_c.Get());
				l_window.draw(l_rect.Get());
				l_window.draw(l_p.Get());
				//sf::sleep(sf::seconds(2));
				l_window.display();
			}
		}
	};

}