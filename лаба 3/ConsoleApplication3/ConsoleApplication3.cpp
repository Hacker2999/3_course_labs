#include <iostream> 
#include <string> 

using namespace std;

class Worker {
	double weight;
	int mood;
public:
	int age;
	string name;

	void show();
	void eat(float howMuch);
	double getWeight();
	int getMood();
	void walking();
	void dancing();
	void working();
};

void Worker::show() {
	cout << "Ваше имя: " << name << endl;
	cout << "Ваш возраст: " << age << endl;
}

void Worker::eat(float howMuch) {
	if (howMuch > 10) {
		age++;
		weight += 0.5 * howMuch;
	}
	else {
		weight += howMuch;
	}
}

double Worker::getWeight() {
	return weight;
}

int Worker::getMood() {
	return mood;
}

void Worker::walking() {
	mood++;
}

void Worker::dancing() {
	mood += 2;
}

void Worker::working() {
	if (mood > 1) {
		mood -= 2;
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	Worker *wrk1 = new Worker();
	string name;
	int age;

	cout << "Введите своё имя: ";
	cin >> name;
	cout << "Введите свой возраст: ";
	cin >> age;
	wrk1->name = name;
	wrk1->age = age;
	wrk1->eat(2);
	wrk1->eat(3);
	wrk1->eat(15);
	wrk1->walking();
	wrk1->walking();
	wrk1->dancing();
	wrk1->dancing();
	wrk1->dancing();
	wrk1->getMood();
	wrk1->show();
	for (int i = 0; i < 9; i++) {
		wrk1->working();
	}
	double ves = wrk1->getWeight();
	cout << "Ваш вес: " << ves << endl;
	cout << "Настроение: " << wrk1->getMood() << endl;
}