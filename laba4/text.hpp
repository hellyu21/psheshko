#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

namespace lu
{

	class mytext
	{
		sf::Text ftext;
		string text;
		sf::Font font;
		//float showtime;

	public:
		mytext() = default;

		mytext(string gottext) {
			ftext.setColor(sf::Color::White);
			ftext.setString(gottext);
			ftext.setFont(font);
		}
	};

}