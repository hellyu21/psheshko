#pragma once
#include <SFML/Graphics.hpp>

namespace lu
{

	class Circle
	{
		float l_r;
		float l_x, l_y;
		float l_v;
		sf::CircleShape l_shape;

	public:
		Circle() = default;

		Circle(float x, float y, float r, float v)
		{
			Setup(x, y, r, v);
		}

		void Setup(float x, float y, float r, float v)
		{
			l_x = x;
			l_y = y;
			l_r = r;
			l_v = v;
			l_shape.setOrigin(l_r, l_r);
			l_shape.setRadius(l_r);
			l_shape.setPosition(l_x, l_y);
			int color_r = rand() % 256;
			int color_g = rand() % 256;
			int color_b = rand() % 256;
			l_shape.setFillColor(sf::Color(color_r, color_g, color_b));
			l_shape.setOutlineThickness(-10.f);
			l_shape.setOutlineColor(sf::Color(color_r, color_g, color_b));
		}

		sf::CircleShape Get()
		{
			return l_shape;
		}

		float Y() { return l_y; }
		float R() { return l_r; }
		float V() { return l_v; }

		void ChangeColor()
		{
			int color_r = rand() % 256;
			int color_g = rand() % 256;
			int color_b = rand() % 256;
			l_shape.setFillColor(sf::Color(color_r, color_g, color_b));
			l_shape.setOutlineThickness(-10.f);
			l_shape.setOutlineColor(sf::Color(color_r, color_g, color_b));
		}

		void ReverseSpeed()
		{
			l_v *= (-1);
		}

		void Move(float dt)
		{
			l_y += l_v * dt;
			l_shape.setPosition(l_x, l_y);
		}
	};

}