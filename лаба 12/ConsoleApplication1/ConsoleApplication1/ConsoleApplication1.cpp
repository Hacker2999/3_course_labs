#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
public:
	double storona1, storona2, gipotenuza;
	void umenshuvel() { // функция уменьшения и увеличения
		cout << "Выберите желаемое действие:\n 1. увеличение\n 2. уменьшение\n"; // выбор действия
		int l;
		cin >> l;
		float proc;
		cout << "Введите число процентов: ";  // выбор числа процентов
		cin >> proc;
		proc = proc / 100.0;
		int cs;
		cout << "Выберите сторону для изменения (1, 2): "; // выбор стороны
		cin >> cs;
		if (l == 1) { // выполнение увеличения/уменьшения
			if (cs == 1) { // выбор стороны
				storona1 += storona1 * proc;
				cout << "Итоговая сторона равна " << storona1; // вывод
			}
			else if (cs == 2) {
				storona2 += storona2 * proc;
				cout << "Итоговая сторона равна " << storona2;
			}
		}
		else if (l == 2) {
			if (cs == 1) {
				storona1 -= storona1 * proc;
				cout << "Итоговая сторона равна " << storona1;
			}
			else if (cs == 2) {
				storona2 -= storona2 * proc;
				cout << "Итоговая сторона равна " << storona2;
			}
		}
	}
	void gipotus() { // нахождение гипотенузы
		gipotenuza = sqrt(storona1 * storona1 + storona2 * storona2);
	}
	void radiusopis() { // нахождение радиуса описанной окружности
		cout << "Радиус описанной окружности равен " << gipotenuza / 2;
	}
	void poluperimetr() { // нахождение полупериметра
		cout << "Полупериметр равен " << (storona1 + storona2 + gipotenuza) / 2;
	}
	void ugli() { // нахождение углов
		double ugol1, ugol2;
		ugol1 = acos((pow(storona1, 2) + pow(gipotenuza, 2) - pow(storona2, 2)) / (2 * storona1 * gipotenuza)) * 180 / 3.1415926535; // углы
		ugol2 = acos((pow(storona2, 2) + pow(gipotenuza, 2) - pow(storona1, 2)) / (2 * storona2 * gipotenuza)) * 180 / 3.1415926535;
		cout << "Углы равны " << ugol1 << " " << 180 - ugol1 - ugol2 << " " << ugol2; // вывод
	}
};



int main()
{
	setlocale(LC_ALL, "ru");
	Triangle mas[3];
	for (int i = 0; i < 3; i++) { // ввод массива прямоугольных треугольников
		cout << "Введите 1 катет " << i + 1 << " треугольника: ";
		cin >> mas[i].storona1;
		cout << "Введите 2 катет " << i + 1 << " треугольника: ";
		cin >> mas[i].storona2;
		mas[i].gipotus(); // вычисление гипотенузы
	}
	cout << endl << "Введите номер желаемого треугольника (от 1 до 3): "; // выбор объекта для выполнения операции
	int t;
	cin >> t;
	t -= 1;
	cout << "Выберите желаемое действие (введите число)\n 1. увеличение/уменьшение размера любой стороны на заданное кол-во процентов\n 2. вычисление радиуса описанной окружности\n 3. вычисление полупериметра\n 4. определение значений углов\n"; // выбор операции для выполнения
	int f;
	cin >> f;
	if (f == 1) { // выполнение операции
		mas[t].umenshuvel();
	}
	else if (f == 2)
	{
		mas[t].radiusopis();
	}
	else if (f == 3)
	{
		mas[t].poluperimetr();
	}
	else if (f == 4)
	{
		mas[t].ugli();
	}
	cout << endl;
}
