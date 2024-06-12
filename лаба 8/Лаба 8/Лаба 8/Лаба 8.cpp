#define _USE_MATH_DEFINES
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
//////////////////////////////////////////////////
class triangle {
protected:
	double a, b, c;
	double alpha, beta, gamma;
	double P;
	double S;
public:
	triangle() {};
	void enter() {
		cout << "Введите стороны треугольника" << endl;
		cout << "сторона А:";
		cin >> a;
		cout << "сторона B:";
		cin >> b;
		cout << "сторона C:";
		cin >> c;
		raschet();
	}
	double getS() {
		return S;
	}
	virtual void show() {
		cout << endl;
		cout << "стороны треугольника:" << endl;
		cout << "сторона А=" << a << endl;
		cout << "сторона B=" << b << endl;
		cout << "сторона C=" << c << endl;
		cout << "углы треугольника:" << endl;
		cout << "угол А=" << alpha << endl;
		cout << "угол B=" << beta << endl;
		cout << "угол C=" << gamma << endl;
		cout << "Периметр треугольника=" << P << endl;
		cout << "Площадь треугольника" << S << endl;
		cout << endl;
	}
	virtual void check() {
		cout << endl;
		if (((b + c - a) < 0) || ((a + c - b) < 0) || ((a + b - c) < 0))
			cout << "треугольник не существует" << endl;
		else
			cout << "треугольник существует" << endl;
		cout << endl;
	}
	void raschet() {
		double temp1, temp2;
		alpha = fabs((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
		temp1 = acos(alpha);
		beta = fabs((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
		temp2 = acos(beta);
		gamma = 180 - (temp1 + temp2);
		S = fabs(0.5 * a * b * sin(a));
		P = a + c + b;
	}

};
////////////////////////////////////////////////
class circle {
private:
	double R;
public:
	double S, P;
	circle() {
		cout << "Введите радиус окружности" << endl;
		cin >> R;
		raschet();
	}
	void show()
	{
		cout << "Площадь окружности = " << S << endl;
		cout << "Длина окружности = " << P << endl;
		cout << endl;
	}
	void raschet() {
		S = M_PI * pow(R,2);
		P = M_PI * 2 * R;
	}
	double getR()const {
		return R;
	}
};
////////////////////////////////////////////
class rtriangle :public triangle {
	circle*_circle;
public:
	rtriangle() {};
	void enter() {
		cout << "Введите стороны треугольника" << endl;
		cout << "стороны = ";
		cin >> a;
		b = a;
		c = a;
		raschet();
	}
	void addcircle(circle* obj)
	{
		_circle = obj;
	}
	void check() {
		cout << endl;
		if (a == b and b == c and a == c)
			cout << "Треугольник равносторонний" << endl;
		else
		{
			cout << "треугольник неравносторонний" << endl;
			a = 0; b = 0; c = 0;
			raschet();
		}
		cout << endl;
	}
	void show() {
		cout << endl;
		cout << "стороны треугольника = " << a << endl;
		cout << "углы треугольника = " << alpha << endl;
		cout << "Периметр треугольника = " << P << endl;
		cout << "Площадь треугольника = " << S << endl;
		cout << endl;
		if (_circle != nullptr)
		{
			_circle->show();
		}
	}
	void circ(const circle& n2) {
		a = (2 * n2.getR())*tan(180 / 3);
		a = b = c;
		raschet();
	}
};

///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	int K, L;
	double temp = 0;
	cout << "Введите кол-во обычных треугольников=";
	cin >> K;
	triangle *tr_arr = new triangle[K];
	for (int i = 0; i < K; i++) {
		tr_arr[i].enter();
		tr_arr[i].check();
	}
	//triangle array[] = new triangle[K];
	cout << "Введите кол-во равносторонних треугольников=";
	cin >> L;
	rtriangle *rtr_arr = new rtriangle[L];
	for (int i = 0; i < L; i++) {
		rtr_arr[i].addcircle(new circle());
	}
	for (int i = 0; i < L; i++) {
		rtr_arr[i].enter();
		rtr_arr[i].show();
		rtr_arr[i].check();
	}


	for (int i = 0; i < K; i++) {
		temp += tr_arr[i].getS();

	}
	cout << "Средняя площадь треугольников=" << temp / K << endl;
	temp = 0;
	for (int i = 0; i < L; i++) {
		if (rtr_arr[i].getS() > temp)
			temp = rtr_arr[i].getS();
	}
	cout << "Наибольший равносторонний треугольник=" << temp << endl;
}
