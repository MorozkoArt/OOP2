#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//////////////////////////
class Krug {
	int radius;
	vector <int> center;


public:
	Krug(int radius, vector <int> center) {
		this->center = center;
		this->radius = radius;
	}
	void print() {
		cout << "Круг: " << "Координаты центра (" << center[0] << ',' << center[1] << ")." << " Радиус = " << radius << endl;
	}
	void peremeshenie_x(int x_1) {
		center[0] += x_1;
	}
	void peremeshenie_y(int y_1) {
		center[1] += y_1;
	}
	void razmer(int new_radius) {
		if (new_radius >= 0) {
			radius = new_radius;
		}
		else {
			cout << "Радиус не может принимать отрицательные значения" << endl;
			cout << "Введите новое значение радиуса" << endl;
			cin >> new_radius;
			razmer(new_radius);
		}
	}
	};
///////////////////////////


class Rectangle {
protected:
	int high;
	int longer;
	vector <vector <double>> koordinat;

public:
	Rectangle(int longer, int high, vector <vector <double>> koordinat) {
		this->high = high;
		this->longer = longer;
		this-> koordinat = koordinat;
	}

	void print_1(int n, int m) {
		cout << "Прямоугольник: Координаты вершин ";
		for (int i = 0; i < n; i++)
		{
			cout << "(";
			for (int j = 0; j < m; j++)
				if (j != m-1) {
					cout << koordinat[i][j] << ",";
				}
				else {
					cout << koordinat[i][j] << ") ";
				}
			
		}
		cout << "Длина = " << longer << " Высота = " << high << endl;
	}
	void peremeshenie_1(int x_2, int y_2, int m, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == 0) {
					koordinat[i][j] += x_2;
				}
				else {
					koordinat[i][j] += y_2;
				}
			}
		}
		
	}
	void razmer_1(int n, int m, int new_longer, int new_high) {
		double ch_longer;
		double ch_high;
		ch_longer = longer - new_longer;
		ch_high = high - new_high;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i==0) {
					if (j == 0) {
						koordinat[i][j] += (ch_longer / 2);
					}
					else {
						koordinat[i][j] += (ch_high / 2);
					}
				}
				if (i == 1) {
					if (j == 0) {
						koordinat[i][j] -= (ch_longer / 2);
					}
					else {
						koordinat[i][j] += (ch_high / 2);
					}
				}
				if (i == 2) {
					if (j == 0) {
						koordinat[i][j] += (ch_longer / 2);
					}
					else {
						koordinat[i][j] -= (ch_high / 2);
					}
				}
				if (i == 3) {
					if (j == 0) {
						koordinat[i][j] -= (ch_longer / 2);
					}
					else {
						koordinat[i][j] -= (ch_high / 2);
					}
				}
				
			}
		}
		this->high = new_high;
		this->longer = new_longer;
	}
	void povorot(int n, int m, int ugol) {
		int koooor;
		koordinat[1][0] = koordinat[1][0] - koordinat[0][0];
		koordinat[1][1] = koordinat[1][1] - koordinat[0][1];
		koordinat[2][0] = koordinat[2][0] - koordinat[0][0];
		koordinat[2][1] = koordinat[2][1] - koordinat[0][1];
		koordinat[3][0] = koordinat[3][0] - koordinat[0][0];
		koordinat[3][1] = koordinat[3][1] - koordinat[0][1];
		for (int i = 1; i < n; i++) {
			koooor = koordinat[i][0];
			koordinat[i][0] = koordinat[i][0] * cos((ugol * 3.14) / 180) - koordinat[i][1] * sin((ugol * 3.14) / 180);
			koordinat[i][1] = koooor * sin((ugol * 3.14) / 180) + koordinat[i][1] * cos((ugol * 3.14) / 180);
		}
		koordinat[1][0] = koordinat[1][0] + koordinat[0][0];
		koordinat[1][1] = koordinat[1][1] + koordinat[0][1];
		koordinat[2][0] = koordinat[2][0] + koordinat[0][0];
		koordinat[2][1] = koordinat[2][1] + koordinat[0][1];
		koordinat[3][0] = koordinat[3][0] + koordinat[0][0];
		koordinat[3][1] = koordinat[3][1] + koordinat[0][1];
	}

};
class Kvadrat : public Rectangle
{
	int high;
	int longer;
	vector <vector <double>> koordinat;
public:
	Kvadrat(int longer, int high, vector <vector <double>> koordinat):Rectangle(longer, high, koordinat){}

};
///////////////////////
int main() {
	///////////////////// Круггггггггггг
	setlocale(LC_ALL, "rus");
	cout << "__________________________________________________________________________" << endl;
	cout << "Круг" << endl;
	cout << "__________________________________________________________________________" << endl;
	int x_c;
	int y_c;
	int r_c;
	cout << "Введите координаты центра круга" << endl;
	cin >> x_c >> y_c;
	std::vector <int> center = { x_c, y_c };
	cout << "Введите размер радиуса круга" << endl;
	cin >> r_c;
	Krug k_1(r_c, center);
	k_1.print();
	int x_1;
	int y_1;
	int new_radius;
	cout << "Введите насколько вы хотите изменить координаты центра круга, для перемещения" << endl;
	cout << "Изменение по оси X" << endl;
	cin >> x_1;
	cout << "Изменение по оси Y" << endl;
	cin >> y_1;
	k_1.peremeshenie_x(x_1);
	k_1.peremeshenie_y(y_1);
	k_1.print();
	cout << "Для изменения размеров круга, введите новый размер радиуса" << endl;
	cin >> new_radius;
	k_1.razmer(new_radius);
	k_1.print();
	cout << "__________________________________________________________________________" << endl;
	cout << "Прямоугольник" << endl;
	cout << "__________________________________________________________________________" << endl;
	/////////////////// прямоуголник
	int n = 4;
	int m = 2;
	int longer;
	int high;
	int x_2;
	int y_2;
	int new_longer;
	int new_high;
	int ugol;
	std::vector <vector<double>> koordinat_1(n, vector<double>(m));
	cout << "Введите координаты вершин прямоугольника например ((0,0), (5,0), (0,3), (5,3))" << endl;
	for (int i = 0; i < n; i++)     
		for (int j = 0; j < m; j++) 
		{
			cin >> koordinat_1[i][j];
		}
	cout << "Введите длину прямоугольника ";
	cin >> longer;
	cout << endl;
	cout << "Введите ширину прямоугольника ";
	cin >> high;
	cout << endl;
	Rectangle k_2(longer, high, koordinat_1);
	k_2.print_1(n,m);
	cout << "Для премещения измените координаты левого нижнего угла прямоугольника" << endl;
	cout << "Введите насколько вы ходите изменить координаты x и y" << endl;
	cin >> x_2 >> y_2;
	k_2.peremeshenie_1(x_2, y_2, m, n);
	k_2.print_1(n, m);
	cout << "Для изменения размеров введите новые значения длины и ширины" << endl;
	cin >> new_longer >> new_high;
	k_2.razmer_1(n, m, new_longer, new_high);
	k_2.print_1(n, m);
	cout << "Для поворота прямоугольника - введите угол, на который хотите повернуть фигуру" << endl;
	cin >> ugol;
	k_2.povorot(n, m, ugol);
	k_2.print_1(n, m);
	cout << "__________________________________________________________________________" << endl;
	cout << "Квадрат" << endl;
	cout << "__________________________________________________________________________" << endl;
	//////////////////////////////////////////////////////////////////// Квадрат
	int n1 = 4;
	int m1 = 2;
	int high1;
	int x1_2;
	int y1_2;
	int new_high1;
	int ugol1;
	std::vector <vector<double>> koordinat_2(n1, vector<double>(m1));
	cout << "Введите координаты вершин квадрата например ((0,0), (5,0), (0,5), (5,5))" << endl;
	for (int i1 = 0; i1 < n1; i1++)
		for (int j1 = 0; j1 < m1; j1++)
		{
			cin >> koordinat_2[i1][j1];
		}
	cout << "Введите ширину квадрата ";
	cin >> high1;
	cout << endl;
	Kvadrat k_3(high1, high1, koordinat_2);
	k_3.print_1(n1, m1);
	cout << "Для премещения измените координаты левого нижнего угла квадрата" << endl;
	cout << "Введите насколько вы ходите изменить координаты x и y" << endl;
	cin >> x1_2 >> y1_2;
	k_3.peremeshenie_1(x1_2, y1_2, m1, n1);
	k_3.print_1(n1, m1);
	cout << "Для изменения размеров введите новое значения ширины " << endl;
	cin >> new_high1;
	k_3.razmer_1(n1, m1, new_high1, new_high1);
	k_3.print_1(n1, m1);
	cout << "Для поворота квадарат - введите угол, на который хотите повернуть фигуру" << endl;
	cin >> ugol1;
	k_3.povorot(n1, m1, ugol1);
	k_3.print_1(n1, m1);
	cout << "__________________________________________________________________________" << endl;

}