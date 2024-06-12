#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
class triangle {
    public:
    double a, b, c;
    double alpha, beta, gamma;
    double P;
    double S;

    triangle() {
        cout << "Введите стороны треугольника" << endl;
        cout << "сторона А:";
        cin >> a;
        cout << "сторона B:";
        cin >> b;
        cout << "сторона C:";
        cin >> c;
        raschet();
    }
    virtual void show() {
        cout << "стороны треугольника:" << endl;
        cout << "сторона А=" << a << endl;
        cout << "сторона B=" << b << endl;
        cout << "сторона C=" << c << endl;
        cout << "углы треугольника:" << endl;
        cout << "угол А=" << alpha << endl;
        cout << "угол B=" << beta << endl;
        cout << "угол C=" << gamma << endl;
        cout << "Периметр треугольника=" << P << endl;
        cout << "Площадь треугольника" <<S<< endl;
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
        S = 0.5 * a * b * sin(a);
        P = a + c + b;
    }
	
};
class rtriangle :public triangle {
public:

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
		cout << "стороны треугольника=" << a << endl;
		cout << "углы треугольника = " << alpha << endl;
		cout << "Периметр треугольника=" << P << endl;
		cout << "Площадь треугольника" << S << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	int K, L;
	double temp=0;
	cout << "Введите кол-во обычных треугольников=";
	cin >> K;
	triangle *tr_arr = new triangle[K];
	for (int i = 0; i < K; i++) {
		tr_arr[i].check();
	}
	cout << "Введите кол-во равносторонних треугольников=";
	cin >> L;
	rtriangle *rtr_arr = new rtriangle[L];
	for (int i = 0; i < L; i++) {
		rtr_arr[i].check();
	}

	for (int i = 0; i < K; i++) {
		temp += tr_arr[i].S;

	}
	cout << "Средняя площадь треугольников=" << temp / K << endl;
	temp = 0;
	for (int i = 0; i < L; i++) {
		if(rtr_arr[i].S>temp)
			temp = rtr_arr[i].S;
	}
	cout << "Наибольший равносторонний треугольник=" << temp << endl;

}

