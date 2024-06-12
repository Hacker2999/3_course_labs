#include <iostream>
using namespace std;

class persona
{
protected:
	static persona* begin;

public:
	persona* next;
	persona* current;

	virtual void ShowInfo() = 0;

	static void ShowList()
	{
		persona* current = begin;
		while (current != nullptr) {
			current->ShowInfo();
			cout << endl;
			current = current->next;
		}
	}
	~persona() {};
};

class employee : virtual public persona
{
protected:
	char* Name;
	int Name_length;
public:
	employee(char* name, int name_length = 32) : Name{ name }, Name_length{ name_length }
	{
		current = begin;
		if (begin != nullptr)
		{
			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else
		{
			begin = this;
		}
	}

	employee() {
		Name_length = 4;
		Name = new char[4]{ 'n','o','n','e' };

		current = begin;
		if (begin != nullptr) {
			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else {
			begin = this;
		}
	}

	void ShowInfo() {
		cout << "Имя рабочего:";
		for (int i = 0; i < Name_length; i++)
		{
			cout << Name[i];
		}
		cout << ". ";
	}

	~employee() {};
};

class sluga : virtual public persona
{
protected:
	char* Name;
	int Name_length;
public:
	sluga(char* name, int name_length = 32) : Name{ name }, Name_length{ name_length }
	{
		current = begin;
		if (begin != nullptr)
		{
			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else
		{
			begin = this;
		}
	}

	sluga() {
		Name_length = 4;
		Name = new char[4]{ 'n','o','n','e' };

		current = begin;
		if (begin != nullptr) {
			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else {
			begin = this;
		}
	}

	void ShowInfo() {
		cout << "Имя служащего:";
		for (int i = 0; i < Name_length; i++)
		{
			cout << Name[i];
		}
		cout << ". ";
	}

	~sluga() {};
};

class  engineer : virtual public persona
{
protected:
	char* Name;
	int Name_length;
public:
	engineer(char* name, int name_length = 32) : Name{ name }, Name_length{ name_length }
	{
		current = begin;
		if (begin != nullptr)
		{
			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else
		{
			begin = this;
		}
	}

	engineer() {
		Name_length = 4;
		Name = new char[4]{ 'n','o','n','e' };

		current = begin;
		if (begin != nullptr) {
			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = this;
			current->next->next = nullptr;
		}
		else {
			begin = this;
		}
	}

	void ShowInfo() {
		cout << "Имя инженера:";
		for (int i = 0; i < Name_length; i++)
		{
			cout << Name[i];
		}
		cout << ". ";
	}

	~engineer() {};
};

persona* persona::begin = nullptr;

int main() {
	setlocale(LC_ALL, "rus");

	char emp_name[] = "Владимир";
	employee first(emp_name, sizeof(emp_name));

	char emp2_name[] = "Генадий";
	employee second(emp2_name, sizeof(emp_name));


	char emp3_name[] = "Артём";
	employee third(emp3_name, sizeof(emp3_name));

	char sluga_name[] = "Василий";
	sluga sluga1(sluga_name, sizeof(sluga_name));

	char sluga2_name[] = "Екатерина";
	sluga sluga2(sluga2_name, sizeof(sluga2_name));

	char sluga3_name[] = "Мария";
	sluga sluga3(sluga3_name, sizeof(sluga3_name));


	char eng_name[] = "Евгений";
	engineer eng1(eng_name, sizeof(eng_name));

	char eng2_name[] = "Евпатий";
	engineer eng2(eng2_name, sizeof(eng2_name));

	char eng3_name[] = "Родион";
	engineer eng3(eng3_name, sizeof(eng3_name));

	persona::ShowList();
	return 0;
}
