#include <iostream>
using namespace std;
float pi = cos(-1);

class R_Complex {
	float r;
	float y;

public:
	//по умолчанию
	R_Complex() = default;

	//полного заполнения
	R_Complex(float gr, float gy)
	{
		r = gr;
		y = gy;
	}

	//копирования
	R_Complex(const R_Complex& other) {
		r = other.r;
		y = other.y;
	}

	//присваивания копированием
	R_Complex& operator=(const R_Complex& other) {
		r = other.r;
		y = other.y;
		return *this;
	}

	//деструктор
	~R_Complex() {
		cout << "Class deleted" << endl;
	}

	//операторы += + * *=
	R_Complex& operator+=(const R_Complex& comp) {
		float a1 = comp.r * cos(comp.y * pi / 180);
		float b1 = comp.r * sin(comp.y * pi / 180);
		float a = r * cos(y * pi / 180) + a1;
		float b = r * sin(y * pi / 180) + b1;
		r = pow((a * a + b * b), 0.5);
		y = atan(abs(b / a)) * 180 / pi;
		if (cos(abs(b / a)) < 0)
			y += 180;
		return *this;
	}

	R_Complex operator+(const R_Complex& comp) {
		float a1 = comp.r * cos(comp.y * pi / 180);
		float b1 = comp.r * sin(comp.y * pi / 180);
		float a = r * cos(y * pi / 180) + a1;
		float b = r * sin(y * pi / 180) + b1;
		r = pow((a * a + b * b), 0.5);
		y = atan(abs(b / a)) * 180 / pi;
		if (cos(abs(b / a)) < 0)
			y += 180;
		return *this;
	}

	R_Complex operator*=(const R_Complex& comp) {
		r *= comp.r;
		y += comp.y;
		return *this;
	}

	R_Complex operator*(const R_Complex& comp) {
		r = r*comp.r;
		y = y + comp.y;
		return *this;
	}

	//оператор ++ префиксный
	R_Complex& operator++() {
		r++;
		return *this;
	}

	//оператор ++ постфиксный
	R_Complex& operator++(int) {
		R_Complex mem = *this;
		r++;
		return mem;
	}

	//оператор ввода
	void set() {
		cin >> r;
		cin >> y;
	}

	//оператор вывода
	void print() {
		cout << r << "*(cos(" << y << ") + i*sin(" << y << "))" << endl;
	}

	float getr() {
		return r;
	}

	float gety() {
		return y;
	}
};

float scalar(R_Complex& a, R_Complex& b) {
	float scal = a.getr() * b.getr() * cos((a.gety() - b.gety())*pi/180);
	return scal;
}

R_Complex absC(R_Complex& a, R_Complex& b) {
	float r1 = a.getr();
	float r2 = b.getr();
	if (r1 > r2) {
			cout << "First is bigger than second" << endl;
			return a;
	}
	if (r2 > r1)
	{
		cout << "Second is bigger than first" << endl;
		return b;
	}
	else
	{
		cout << "They are equal" << endl;
		return a;
	}
}

string qC(R_Complex& a) {
	float alphag = a.gety();
	float r = a.getr();
	if (r == 0 || (int(alphag) %360 == 0) || (alphag > 0 && alphag < 90)) {
		return "First";
	}
	else if ((int(alphag) % 270 == 0) || (alphag > 270 && alphag < 360)) {
		return "Forth";
	}
	else if ((int(alphag) % 180 == 0) || (alphag > 180 && alphag < 270)) {
		return "Third";
	}
	else if ((int(alphag) % 90 == 0) || (alphag > 90 && alphag < 180)) {
		return "Second";
	}
}

int main() {
	R_Complex c1(4, 30);
	R_Complex c2(pow(2, 0.5), 45);
	R_Complex c3(2*pow(2, 0.5), 180);
	cout << scalar(c2, c1) << endl;
	R_Complex c6 = absC(c3, c1);
	c6.print();
	R_Complex c4(14, 89);
	cout << qC(c4) << endl;
	R_Complex c5;
	c5 = c2 + c3;
	c1.print();
	c5.print();
	return 0;
}
