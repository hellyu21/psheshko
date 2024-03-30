#include <iostream>
using namespace std;

class R_Complex {
	float r;
	float y;
	float pi = cos(-1);

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
	R_Complex& operator = (const R_Complex& other) {
		R_Complex new(0,0);
	}

	//деструктор
	~R_Complex() {
		cout << "Class deleted" << endl;
	}

	//операторы += + *=
	//

	//оператор ++
	//

	//оператор ввода
	void set() {
		cin >> r;
		cin >> y;
	}

	//оператор вывода
	void print() {
		cout << r << "*(cos(" << y << ") + i*sin(" << y << "))" << endl;
	}
};

int main(){
	R_Complex roar(0,0);
	roar.set();
	roar.print();
	return 0;
}