
#include <iostream>
#include<string>
using namespace std;

class employee;
class director;
class firm;
class leader_of_firm;
class leader_of_gov_firm;
class leader_of_OOO_firm;

class employee
{
public:
	string name  = "Иван Иванов";
};

class director : public employee
{
public:
	string otdel = "Отдел кадров";
};

class firm
{
public:
	string firma= "Хлебные нарды";
};

class leader_of_firm : public firm, public director
{
public:
	 double numb_of_sub = 500000;
	  
	virtual void show()
	{
		cout << "Фирма: " << firma << endl;
		cout << "Отдел: " << otdel << endl;
		cout << "Кол-во подчинённых: " <<numb_of_sub << endl;
		cout << "Имя: " << name << endl;
		cout << endl;
	}
};

class leader_of_gov_firm : public leader_of_firm
{
public:
	string type = "Государственная";

	void show() override
	{
		cout << "Фирма: " << firma << endl;
		cout << "Тип компании:" << type << endl;
		cout << "Отдел: " << otdel << endl;
		cout << "Кол-во подчинённых: " << numb_of_sub << endl;
		cout << "Имя: " << name << endl;
		cout << endl;
	}
};

class leader_of_OOO_firm : public leader_of_firm
{
public:
	string type = "ООО";

	void show() override
	{
		cout << "Фирма: " << firma << endl;
		cout << "Тип компании:" << type << endl;
		cout << "Отдел: " << otdel << endl;
		cout << "Кол-во подчинённых: " << numb_of_sub << endl;
		cout << "Имя: " << name << endl;
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	leader_of_gov_firm firma1;
	leader_of_OOO_firm firma2;

	firma1.show();

	firma2.show();

	return 0;
}