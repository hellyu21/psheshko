#pragma once
#include <SFML/Graphics.hpp>

namespace lu
{

	class Poly
	{
		float l_a, l_n;
		float l_x, l_y;
		float l_v;
		sf::CircleShape l_shape;

	public:
		Poly() = default;

		Poly(float x, float y, float a, float n, float v)
		{
			Setup(x, y, a, n, v);
		}

		void Setup(float x, float y, float a, float n, float v)
		{
			l_x = x;
			l_y = y;
			l_a = a;
			l_n = n;
			l_v = v;
			l_shape.setOrigin(a, a);
			l_shape.setPointCount(n);
			l_shape.setRadius(a);
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
		float A() { return l_a; }
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