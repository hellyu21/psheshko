#pragma once
#include "figure.hpp"
using namespace std;

class Para : public Figure {
private:
	double ps[8];
public:
	Para() = default;
	Para(double gps[], string gcolor) {
		for (int i = 0; i < 8; i++) {
			ps[i] = gps[i];
		}
		color = gcolor;
	}

	~Para() = default;

	//метод площади
	double place() {
		double AB = pow(pow(ps[2] - ps[0], 2) + pow(ps[3] - ps[1],2), 0.5);
		double AC = pow(pow(ps[4] - ps[0], 2) + pow(ps[5] - ps[1], 2), 0.5);
		double cs = ((ps[2] - ps[0]) * (ps[4] - ps[0]) + (ps[3] - ps[1]) * (ps[5] - ps[1])) / (AB * AC);
		double sn = pow(1 - pow(cs, 2), 0.5);
		double s = AB * AC * sn;
		return s;
	}

	string figin() {
		string info = "Тип: Паралеллепипед,\nЦвет: " + color + ",\nВершины: ";
		info += "A(" + to_string(ps[0]) + ", " + to_string(ps[1]) + "), B(" + to_string(ps[2]) + ", " + to_string(ps[3]) + "), C(" + to_string(ps[4]) + ", " + to_string(ps[5]) + "), D(" + to_string(ps[6]) + ", " + to_string(ps[7]) + "),\n";
		info += "Площадь: " + to_string(place());
		return info;
	}
};