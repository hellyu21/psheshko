#pragma once
#include "figure.hpp"
#include <string>
using namespace std;

class Tria : public Figure{
private:
	double ps[6];
public:
	Tria() = default;

	Tria(double gps[], string gcolor) {
		for (int i = 0; i < 6; i++) {
			ps[i] = gps[i];
		}
		color = gcolor;
	}

	~Tria() = default;

	//метод площади
	double place() {
		double s = 0.5 * (ps[0] * (ps[3] - ps[5]) + ps[2] * (ps[5] - ps[1]) + ps[4] * (ps[1] - ps[3]));
		return s;
	}

	string figin() {
		string info = "Тип: Треугольник,\nЦвет: " + color + ",\nВершины: ";
		info += "A(" + to_string(ps[0]) + ", " + to_string(ps[1]) + "), B(" + to_string(ps[2]) + ", " + to_string(ps[3]) + "), C(" + to_string(ps[4]) + ", " + to_string(ps[5]) + "),\n";
		info += "Площадь: " + to_string(place());
		return info;
	}
};