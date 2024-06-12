#include <iostream> 

using namespace std;

class foo {
};
class bar {
};

class baz :bar {
};
class quux :bar {
};

class StaticCast {
	int i = 5;
	double d = 111.222;
	char c = 'a';
	int* pi = &i;
	double* pd = &d;
	const int* cpi = &i;
	void* pv = NULL;
	foo oFoo;
	bar oBar;
	baz oBaz;
	quux oQuux;
	foo* pFoo = &oFoo;
	bar* pBar = &oBar;
	baz* pBaz = &oBaz;
	quux* pQuux = &oQuux;
public:
	StaticCast() {}
	~StaticCast() {}
	void manipulations() {
		//Приводим явно double к int
		i = static_cast<int>(d);
		cout << "Приведение double " << d << " к int " << i << " выполнено\n";
		//и наоборот
		d = static_cast<int>(i);
		cout << "Приведение int " << i << " к double " << d << " выполнено\n";
		//указатель на int к char
		//c = static_cast<char>(pi);
		cout << "Приведение int* " << pi << " к char " << c << " провалено\n";
		//char к указателю на void
		//pv = static_cast<void*>(c);
		cout << "Приведение char " << c << " к void* " << pv << " провалено\n";
		//указатель на void к указателю на int
		pi = static_cast<int*>(pv);
		cout << "Приведение void* " << pv << " к int* " << pi << " выполнено\n";
		//Снимаем константность const int*
		//pi = static_cast<int*>(cpi);
		cout << "Приведение const int* " << cpi << " к int " << pi << " провалено\n";
		//Приводим указатель на объект bar к указателю на объект foo
		//из разных иерархий
		//pFoo = static_cast<foo*>(pBar);
		cout << "Приведение указателя на объект к указателю из другой иерархии провалено\n";
		//Приводим указатель на double к double
		//d = static_cast<double>(pd);
		cout << "Приведение double* " << pd << " к double " << d << " провалено\n";
		//Перемещение из одной иерархии наследования в другую
		//pBar = static_cast<bar*>(pBaz);
		//pQuux = static_cast<quux*>(pBar);
		cout << "Перемещение из одной иерархии наследования в другую провалено\n";
	}
	void manipulations2() {
		float chislo = -43254364362377743543829749823754564.8543687583249050329057324324857834868943;
		cout << "Число " << chislo << " типа float ";
		double cifra = static_cast<double>(chislo);
		cout << "преобразуем в double\n" << cifra << endl;
		int n = static_cast<int>(cifra);
		cout << "Полученное значение преобразуем в int: " << n << endl;
		bool x = static_cast<bool>(n);
		cout << "Преобразуем int в bool: ";
		cout << x;
		cout << endl << "А теперь из bool получим char\n";
		char hh = static_cast<char>(x);
		cout << hh << "\nИ, наконец, из char получим long double\n";
		long double res = static_cast<long double>(hh);
		cout << res;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	StaticCast t;
	t.manipulations();
	cout << endl;
	t.manipulations2();
}
