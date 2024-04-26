#pragma once
using namespace std;

class Figure {
protected:
	string color;
public:
	Figure() = default;

	Figure(string gcolor) {
		color = gcolor;
	}

	//метод площади
	virtual double place()  = 0;

	//метод вывода
	virtual string figin() = 0;
};