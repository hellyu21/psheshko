#include <iostream>
using namespace std;


template <typename t>
class Matrix {
	int n;
	int m;
	t mat[n][m];
public:
	//по умолчанию
	Matrix() = default;

	//полного заполнения
	Matrix(int gn, int gm, t& gmat[gn*gm])
	{
		n = gn;
		m = gm;
		for (int i = 0; i < n; i++)
			for (int j = 1; j < m+1; j++)
				mat[i][j] = gmat[3*i + j];
 	}

	void getnm() {
		cout << n << " " << m << endl;
	}

	void getin() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
	}
	//копирования
	//Matrix(const Matrix& other) = default();

	////присваивания
	//Matrix& operator=(const Matrix& other) = default();

	////операторы ввода и вывода
	//Matrix operator<<(const Matrix& gmat) {
	//	for (int i = 0; i < gmat.n; i++) {
	//		for (int j = 0; j < gmat.m; j++)
	//			cout << gmat.mat[i][j] << " ";
	//		cout << endl;
	//	}
	//}

	////деструктор
	//~Matrix() = default();

	////операторы += + * *=
	//Matrix& operator+=(const Matrix& smat) {
	//	for (int i = 0; i < n; i++)
	//		for (int j = 1; j < m + 1; j++) {
	//			mat[i][j] += smat[i][j];
	//		}
	//	return *this;
	//}

	//Matrix operator+(const Matrix& smat) {
	//	Matrix rmat;
	//	for (int i = 0; i < n; i++)
	//		for (int j = 1; j < m + 1; j++) {
	//			rmat.mat[i][j] = mat[i][j] + smat[i][j];
	//		}
	//	return rmat;
	//}

	//Matrix operator+(const Matrix& smat) {
	//	Matrix rmat;
	//	for (int i = 0; i < n; i++)
	//		for (int j = 1; j < m + 1; j++) {
	//			rmat.mat[i][j] = mat[i][j] - smat[i][j];
	//		}
	//	return rmat;
	//}

	//Matrix operator*=(const Matrix& smat) {
	//	for (int i = 0; i < n; i++)
	//		for (int j = 0; j < m; j++) {
	//			t tmp = 0;
	//			for (int z = 0, z < m; z++) {
	//				tmp += mat[i][z] * smat[z][j];
	//			}
	//			mat[i][j] = tmp;
	//		}
	//	return *this;
	//}

	//Matrix operator*(const Matrix& smat) {
	//	Matrix rmat;
	//	for (int i = 0; i < n; i++)
	//		for (int j = 0; j < m; j++) {
	//			t tmp = 0;
	//			for (int z = 0, z < m; z++) {
	//				tmp += mat[i][z] * smat[z][j];
	//			}
	//			rmat[i][j] = tmp;
	//		}
	//	return rmat;
	//}

	/*Matrix operator*t() {

	}*/
};

int main() {
	int tmp[6] = { 1, 2, 3, 4, 5, 6 };
	Matrix<int> mat(2, 3, tmp);
	mat.getnm();
	mat.getin();
}
