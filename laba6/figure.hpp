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

	//����� �������
	virtual double place()  = 0;

	//����� ������
	virtual string figin() = 0;
};