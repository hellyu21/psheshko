#pragma once
#include <SFML/Graphics.hpp>

namespace lu
{

	class Circle
	{
		float l_r;
		float l_x, l_y;
		float l_v;
		float l_alfa;
		sf::CircleShape l_shape;

	public:
		Circle() = default;

		Circle(float x, float y, float r, float v, float alfa)
		{
			Setup(x, y, r, v, alfa);
		}

		void Setup(float x, float y, float r, float v, float alfa)
		{
			l_x = x;
			l_y = y;
			l_r = r;
			l_v = v;
			l_alfa = alfa;
			l_shape.setOrigin(l_r, l_r);
			l_shape.setRadius(l_r);
			l_shape.setPosition(l_x, l_y);/*
			int color_r = rand() % 256;
			int color_g = rand() % 256;
			int color_b = rand() % 256;*/
			l_shape.setFillColor(sf::Color(250, 1, 1));
			l_shape.setOutlineThickness(-10.f);
			l_shape.setOutlineColor(sf::Color(250, 1, 1));
		}

		sf::CircleShape Get()
		{
			return l_shape;
		}

		float X() { return l_x; }
		float Y() { return l_y; }
		float R() { return l_r; }
		float Alfa() { return l_alfa; }
		void Alfa(float alfa) {
			l_alfa = alfa;
		}


		void Move(float dt)
		{
			float vx = l_v * cos(l_alfa);
			float vy = l_v * sin(l_alfa);
			l_x += vx * dt;
			l_y += vy * dt;
			l_shape.setPosition(l_x, l_y);
		}
	};

}