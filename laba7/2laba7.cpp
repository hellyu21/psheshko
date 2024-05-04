#include <iostream>
using namespace std;


template<typename t>
class Matrix {
public:
	t **mas;
	int n;
	int m;

	//по умолчанию
	Matrix() = default;

	//деструктор
	~Matrix() = default;

	//полного заполнения
	Matrix(int gn, int gm, t *gmas)
	{
		n = gn;
		m = gm;
		mas = new t * [n];
		for (int i = 0; i < n; i++) {
			mas[i] = new t[m];
			for (int j = 0; j < m; j++) {
				mas[i][j] = gmas[m * i + j];
			}
		}
	}

	//копирования
	Matrix(const Matrix& other) {
		n = other.n;
		m = other.m;
		mas = new t * [n];
		for (int i = 0; i < n; i++) {
			mas[i] = new t[m];
			for (int j = 0; j < m; j++) {
				mas[i][j] = other.mas[i][j];
			}
		}
	};

	//присваивания
	Matrix& operator=(const Matrix& other) {
		n = other.n;
		m = other.m;
		mas = new t * [n];
		for (int i = 0; i < n; i++) {
			mas[i] = new t[m];
			for (int j = 0; j < m; j++) {
				mas[i][j] = other.mas[i][j];
			}
		}
		return *this;
	};

	//операторы ввода и вывода
	friend istream& operator>>(istream& is, Matrix& mat) {
		int gn, gm;
		is >> gn >> gm;
		t *mass = new t[gn*gm]{};
		for (int i = 0; i < gn*gm; i++) {
			is >> mass[i];
		}

		Matrix tmp(gn, gm, mass);
		mat = tmp;
		return is;
	}

	friend ostream& operator<<(ostream& os, const Matrix& mat) {
		for (int i = 0; i < mat.n; i++) {
			for (int j = 0; j < mat.m; j++)
				os << mat.mas[i][j] << " ";
			os << endl;
		}
		return os;
	}

	//операторы +=....
	Matrix operator+(const Matrix& smat) {
		
		if ((n == smat.n) && (m == smat.m)) {
			t *mass = new t[n*m]{ 0 };
			Matrix rmat(n, m , mass);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					rmat.mas[i][j] = mas[i][j] + smat.mas[i][j];
				}
			return rmat;
		}
		else {
			int *mas = new int[1]{ 9999 };
			Matrix rmat(1, 1, mas);
			cout << "Error" << endl;
			return rmat;
		}
	}

	Matrix operator+=(const Matrix& smat) {
		Matrix rmat = *this + smat;
		*this = rmat;
		return *this;
	}

	Matrix operator-(const Matrix& smat) {

		if ((n == smat.n) && (m == smat.m)) {
			t *mass = new t[n * m]{ 0 };
			Matrix rmat(n, m, mass);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					rmat.mas[i][j] = mas[i][j] - smat.mas[i][j];
				}
			return rmat;
		}
		else {
			int *mas = new int[1] { 9999 };
			Matrix rmat(1, 1, mas);
			cout << "Error" << endl;
			return rmat;
		}
	}

	Matrix operator-=(const Matrix& smat) {
		Matrix rmat = *this - smat;
		*this = rmat;
		return *this;
	}


	Matrix operator*(const Matrix& smat) {
		if (m == smat.n) {
			t *tmp = new t[n * smat.m]{ 0 };
			for (int i = 0; i < n; i++)
				for (int j = 0; j < smat.m; j++) {
					for (int z = 0; z < m; z++) {
						tmp[smat.m * i + j] += mas[i][z] * smat.mas[z][j];
					}
				}
			Matrix rmat(n, smat.m, tmp);		
			return rmat;
		}
		else {
			int *u = new int[1]{ 9999 };
			Matrix rmat(1, 1, u);
			cout << "Error" << endl;		
			return rmat;
		}
	}

	Matrix operator*=(const Matrix& smat) {
		Matrix rmat = *this * smat;
		*this = rmat;		
		return *this;
	}

	//увеличение на 1
	Matrix operator++(int) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				mas[i][j]++;
			}
		return *this;
	}

	//определитель матрицы
	t det() {
		if (n == m) {
			if (n == 1) {
				return mas[0][0];
			}
			if (n == 2) {
				t a = mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
				return a;
			}
			if (n == 3) {
				t a = mas[0][0] * (mas[1][1] * mas[2][2] - mas[2][1] * mas[1][2]) - mas[0][1] * (mas[1][0] * mas[2][2] - mas[2][0] * mas[1][2]) + mas[0][2] * (mas[1][0] * mas[2][1] - mas[2][0] * mas[1][1]);
				return a;
			}
		}
		else {
			cout << "Error" << endl;
			return 9999;
		}
	}

	//удаление строки
	Matrix del(int k) {
		if ((k >= 0) && (k <= n - 1)) {
			t *newmas = new t [(n - 1)*m] {0};
			Matrix nmat(n - 1, m, newmas);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i < k)
						nmat.mas[i][j] = mas[i][j];
					else if (i > k)
						nmat.mas[i - 1][j] = mas[i][j];
				}
			}
			return nmat;
		}
	}
};

int main()
{
	int a[9] = { 1, 2, 3, 4 ,5 ,6 ,7, 8, 9 };
	int b[9] = { 1, 2, 3, 2 , 4, 6 ,1 ,3 ,7 };
	int c[6] = { 5,5 , 4, 3, 3, 2 };
	Matrix<int> A(3, 3, a);
	Matrix<int> B(3, 3, b);
	Matrix<int> C(2, 3, c);
	cout << A << endl << B << endl << C << endl;
	Matrix<int> D = A + B;
	cout << D << endl;
	D = D - B;
	cout << D << endl;
	D += B;
	cout << D << endl;
	D *= B;
	cout << D << endl;


	Matrix<int> E = A * C;
	cout << E << endl;
	Matrix<int> F = C * B;
	cout << F << endl;
	int Z = B.det();
	cout << Z << endl;
	A = A.del(1);
	cout << A << endl;
}
