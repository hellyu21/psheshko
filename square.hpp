#pragma once
#include <SFML/Graphics.hpp>

namespace lu
{

	class Rect
	{
		float l_a, l_b;
		float l_x, l_y;
		float l_v;
		sf::RectangleShape l_shape;

	public:
		Rect() = default;

		Rect(float x, float y, float a, float b, float v)
		{
			Setup(x, y, a, b, v);
		}

		void Setup(float x, float y, float a, float b, float v)
		{
			l_x = x;
			l_y = y;
			l_a = a;
			l_b = b;
			l_v = v;
			l_shape.setOrigin(a/2, b/2);
			l_shape.setSize(sf::Vector2 (a, b));
			l_shape.setPosition(l_x, l_y);
			int color_r = rand() % 256;
			int color_g = rand() % 256;
			int color_b = rand() % 256;
			l_shape.setFillColor(sf::Color(color_r, color_g, color_b));
			l_shape.setOutlineThickness(-10.f);
			l_shape.setOutlineColor(sf::Color(color_r, color_g, color_b));
		}

		sf::RectangleShape Get()
		{
			return l_shape;
		}

		float Y() { return l_y; }
		float B() { return l_b; }
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