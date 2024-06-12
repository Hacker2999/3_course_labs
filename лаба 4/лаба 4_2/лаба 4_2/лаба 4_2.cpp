#include <iostream>
#include <time.h>
#include <string>
using namespace std;
class clocks {
public:
	int hour;
	int minutes;
	int seconds;
	int mseconds;
	void show_time();
	clocks operator+(const clocks& n2);
	clocks operator-(const clocks& n2);
	clocks operator=(const clocks& n2);
	clocks();
	clocks(string name);
	~clocks();
};
clocks clocks:: operator=(const clocks& n2) {
	//проверка на самоприсваивание
	if (this == &n2) {
		return *this;
	}
	this->hour = n2.hour;
	this->minutes = n2.minutes;
	this->seconds = n2.seconds;
	this->mseconds = n2.mseconds;
	return *this;
}
clocks clocks::operator+(const clocks& n2)
{
	bool flag = true;
	clocks temp;
	temp.hour = this->hour + n2.hour;
	temp.minutes = this->minutes + n2.minutes;
	temp.seconds = this->seconds + n2.seconds;
	temp.mseconds = this->mseconds + n2.mseconds;
	while (flag) {
		if (temp.hour < 24)
		{
			flag = false;
		}
		else
		{
			temp.hour -= 24;
			flag = true;
		}
		if (temp.minutes < 60)
		{
			flag = false;
		}
		else
		{
			temp.hour++;
			temp.minutes -= 60;
			flag = true;
		}
		if (temp.seconds < 60)
		{
			flag = false;
		}
		else
		{
			temp.minutes++;
			temp.seconds -= 60;
			flag = true;
		}
		if (temp.mseconds < 1000)
		{
			flag = false;
		}
		else
		{
			temp.seconds++;
			temp.mseconds -= 1000;
			flag = true;
		}
	}
	return (temp);
}
clocks clocks::operator-(const clocks& n2)
{
	bool flag = true;
	clocks temp;
	temp.hour = this->hour - n2.hour;
	temp.minutes = this->minutes - n2.minutes;
	temp.seconds = this->seconds - n2.seconds;
	temp.mseconds = this->mseconds - n2.mseconds;
	while (flag) {
		if (temp.hour > 0) 
		{
			flag = false;
		}
		else
		{
			temp.hour += 24;
			flag = true;
		}
		if (temp.minutes > 0)
		{
			flag = false;
		}
		else
		{
			temp.minutes += 60;
			flag = true;
		}
		if(temp.seconds>0)
		{
			flag = false;
		}
		else
		{
			temp.seconds += 60;
			flag = true;
		}
		if (temp.mseconds>0)
		{
			flag = false;
		}
		else
		{
			temp.mseconds += 1000;
			flag = true;
		}
	}
	return (temp);
}
clocks::clocks(string name) {
	cout << "Часы " << name << endl;
	cout << "Введите время" << endl;
	cout << "часы:";
	cin >> hour;
	cout << "минуты:";
	cin >> minutes;
	cout << "секунды:";
	cin >> seconds;
	cout << "миллисекунды:";
	cin >> mseconds;
	if ((hour < 0 or hour>24) or (minutes < 0 or minutes>60) or (seconds < 0 or seconds>60) or (mseconds < 0 or mseconds>1000))
	{
		cout << "Ошибка ввода времени" << endl;
		exit(-1);
	}
	cout << endl;
}

void clocks::show_time()
{
	cout << endl;
	cout << "Время сейчас:" << endl;
	cout << "Часы:" << hour << endl;
	cout << "Минуты:" << minutes << endl;
	cout << "Секунды:" << seconds << endl;
	cout << "Миллисекунды:" << mseconds << endl;
	cout << endl;
}
clocks::clocks()
{
}
clocks::~clocks() {
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));

	clocks soviet("советские");
	clocks modern("современные");
	clocks us;
	us = soviet + modern;
	cout << "Операция сложения" << endl;
	us.show_time();
	us = soviet - modern;
	cout << "Операция вычитания" << endl;
	us.show_time();
}
