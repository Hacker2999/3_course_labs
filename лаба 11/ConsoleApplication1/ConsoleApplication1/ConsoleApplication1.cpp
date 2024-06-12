#include <iostream>

using namespace std;

class кг;
class Мг;
class г;
class мг;
class мкг;

class кг {
	double m = 0;
public:
	кг();
	кг(double x);
	кг(Мг* o);
	operator Мг();
	кг(г* o);
	operator г();
	кг(мг* o);
	operator мг();
	кг(мкг* o);
	operator мкг();
	double Value() {
		return m;
	}
};

class Мг {
	double m = 0;
public:
	Мг();
	Мг(double x);
	Мг(кг* o);
	operator кг();
	Мг(г* o);
	operator г();
	Мг(мг* o);
	operator мг();
	Мг(мкг* o);
	operator мкг();
	double Value() {
		return m;
	}
};

class г {
	double m = 0;
public:
	г();
	г(double x);
	г(Мг* o);
	operator Мг();
	г(кг* o);
	operator кг();
	г(мг* o);
	operator мг();
	г(мкг* o);
	operator мкг();
	double Value() {
		return m;
	}
};

class мг {
	double m = 0;
public:
	мг();
	мг(double x);
	мг(Мг* o);
	operator Мг();
	мг(г* o);
	operator г();
	мг(кг* o);
	operator кг();
	мг(мкг* o);
	operator мкг();
	double Value() {
		return m;
	}
};

class мкг {
	double m = 0;
public:
	мкг();
	мкг(double x);
	мкг(Мг* o);
	operator Мг();
	мкг(г* o);
	operator г();
	мкг(мг* o);
	operator мг();
	мкг(кг* o);
	operator кг();
	double Value() {
		return m;
	}
};

кг::кг() {}
кг::кг(double x) {
	m = x;
}
кг::кг(Мг* o) {
	m = o->Value() * 1000;
}
кг::operator Мг() {
	return m / 1000;
}
кг::кг(г* o) {
	m = o->Value() / 1000;
}
кг::operator г() {
	return m * 1000;
}
кг::кг(мг* o) {
	m = o->Value() / 1000000;
}
кг::operator мг() {
	return m * 1000000;
}
кг::кг(мкг* o) {
	m = o->Value() / 1000000000;
}
кг::operator мкг() {
	return m * 1000000000;
}

Мг::Мг() {}
Мг::Мг(double x) {
	m = x;
}
Мг::Мг(кг* o) {
	m = o->Value() / 1000;
}
Мг::operator кг() {
	return m * 1000;
}
Мг::Мг(г* o) {
	m = o->Value() * 1000000;
}
Мг::operator г() {
	return m / 1000000;
}
Мг::Мг(мг* o) {
	m = o->Value() / 1000000000;
}
Мг::operator мг() {
	return m * 1000000000;
}
Мг::Мг(мкг* o) {
	m = o->Value() / 1000000000000;
}
Мг::operator мкг() {
	return m * 1000000000000;
}

г::г() {}
г::г(double x) {
	m = x;
}
г::г(Мг* o) {
	m = o->Value() * 1000000;
}
г::operator Мг() {
	return m / 1000000;
}
г::г(кг* o) {
	m = o->Value() * 1000;
}
г::operator кг() {
	return m / 1000;
}
г::г(мг* o) {
	m = o->Value() / 1000;
}
г::operator мг() {
	return m * 1000;
}
г::г(мкг* o) {
	m = o->Value() / 1000000;
}
г::operator мкг() {
	return m * 1000000;
}

мг::мг() {}
мг::мг(double x) {
	m = x;
}
мг::мг(Мг* o) {
	m = o->Value() * 1000000000;
}
мг::operator Мг() {
	return m / 1000000000;
}
мг::мг(г* o) {
	m = o->Value() * 1000;
}
мг::operator г() {
	return m / 1000;
}
мг::мг(кг* o) {
	m = o->Value() * 1000000;
}
мг::operator кг() {
	return m / 1000000;
}
мг::мг(мкг* o) {
	m = o->Value() / 1000;
}
мг::operator мкг() {
	return m * 1000;
}

мкг::мкг() {}
мкг::мкг(double x) {
	m = x;
}
мкг::мкг(Мг* o) {
	m = o->Value() * 1000000000000;
}
мкг::operator Мг() {
	return m / 1000000000000;
}
мкг::мкг(г* o) {
	m = o->Value() * 1000000;
}
мкг::operator г() {
	return m / 1000000;
}
мкг::мкг(мг* o) {
	m = o->Value() * 1000;
}
мкг::operator мг() {
	return m / 1000;
}
мкг::мкг(кг* o) {
	m = o->Value() * 1000000000;
}
мкг::operator кг() {
	return m / 1000000000;
}

int main()
{
	setlocale(LC_ALL, "rus");
	кг kg(1000000);
	Мг Mg = kg;
	cout << kg.Value() << " килогамм = " << Mg.Value() << " мегаграмм\n";
	мкг mkg = Mg;
	cout << Mg.Value() << " мегаграмм = " << mkg.Value() << " микрограмм\n";
	kg = mkg;
	cout << mkg.Value() << " микрограмм = " << kg.Value() << " килогамм\n";
}
