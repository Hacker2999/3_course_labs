#include <iostream>
#define PI 3.14159265
using namespace std;
//класс кругов
class Circle
{
private:
	//поля класса, известные данные
	int R;
public:
	void set_R(int Rp) {
		R = Rp;
	}
	int get_R() {
		return R;
	}
	
	
	//сбор размеров окружностей
	void Size(int i) {
		int temp;
		cout << "Введите радиус окружности №"<<i<<' ';
		cin >> temp;
		if (temp <= 0)
		{
			cout << "error" << endl;
			exit(-1);
		}
		else
			set_R(temp);
	}
	//метод изменения размера на определённый процент
	void change_size() {
		int choice;
		int procent;
		cout << "Введите какую операцию хотите провести:" << endl;
		cout << "1-Увеличение" << endl;
		cout << "2-Уменьшение" << endl;
		cin >> choice;
		cout << endl;
		cout << "Введите на какой процент хотите провести операцию ";
		cin >> procent;
		if (choice == 1) {
			R = R + R * (procent / 100.0);
			cout << "Размер:" << R << endl;
		}
		else if (choice == 2)
		{
			R = R - R * (procent / 100.0);
			cout << "Размер:" << R << endl;
		}
		else {
			cout << "error" << endl;
			exit(-1);
		}
	}
	//метод вычисления длины и площади круга
	void LScounter() {
		cout << endl;
		cout << "Длина окружности: " << 2 * PI * R << endl;
		cout << "Площадь круга: " << PI * pow(R, 2) << endl;
	}
	//метод вычисления диаметра
	void Diameter() {
		cout << endl;
		cout << "Диаметр окружности=" << 2 * R << endl;
	}
	//метод выбора нужной операции
	void operation() {
		int choice;
		cout << endl;
		cout << "Выберите нужную операцию:" << endl;
		cout << "1-увеличение/уменьшение размера на определённый процент" << endl;
		cout << "2-Вычисление длины окружности и площади круга" << endl;
		cout << "3-Определение диаметра" << endl;
		cin >> choice;
		if (choice == 1) {
			change_size();
		}
		else if (choice == 2) {
			LScounter();
		}
		else if (choice == 3) {
			Diameter();
		}
		else
		{
			cout << "error" << endl;
			exit(-1);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	int count;
	int numb;
	//ввод пользователем нужного кол-ва окр-тей
	cout << "Введите кол-во окружностей ";
	cin >> count;
	cout << endl;
	//объявление массива объектов класса
	Circle* circles=new Circle [count];
	//цикл для ввода размеров объектов
	for (int i = 0; i < count; i++) {
		circles[i].Size(i + 1);
	}
	cout << endl;
	cout << "Выберите номер окружности ";
	cin >> numb;
	if (numb < 0 or numb>count) {
		cout << "error"<<endl;
		exit(-1);
	}
	else {
		circles[numb - 1].operation();
	}
	return 0;
}
