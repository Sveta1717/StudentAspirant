
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector> 
using namespace std;

class Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;

public:
	Date(unsigned short d = 1, unsigned short m = 1, unsigned short y = 2000)
	{
		day = d;
		month = m;
		year = y;
	}

	void SetDay(unsigned short day)
	{
		if (((month = 1 && day < 32) || (month = 3 && day < 32) ||
			(month = 4 && day < 31) || (month = 5 && day < 32) || (month = 6 && day < 31) ||
			(month = 7 && day < 32) || (month = 8 && day < 32) || (month = 9 && day < 31) ||
			(month = 10 && day < 32) || (month = 11 && day < 31) || (month = 12 && day < 32)) &&
			((month = 2 && day < 29) && (year % 4 != 0 && year % 100 == 0 || year % 400 != 0) ||
				(month = 2 && day < 30) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)))
		{
			this->day = day;
		}
	}

	void SetMonth(unsigned short month)
	{
		if (month < 13)
			this->month = month;
	}

	void SetYear(unsigned short year)
	{
		if (year > 1930 || year < 2012)
			this->year = year;
	}

	const unsigned short GetDay() const
	{
		return day;
	}

	const unsigned short GetMonth() const
	{
		return month;
	}

	const unsigned short GetYear() const
	{
		return year;
	}
};

class Student
{
	char* surname;
	char* name;
	char* patronymic;
	char* adress;
	char* phone;
	vector<int> marks;
	int counterMarks = 0;
	vector<int> coursework;
	int counterCoursework = 0;
	vector<int> exam;
	int counterExam = 0;
	Date d;

public:	

	Student() : Student("No surname", "No name", "No patronymic", 10/10/2000, "No adress", "No phone")
	{
	}
	Student(const char* surname, const char* name, const char* patronymic)
	{
		this->surname = new char[100];
		strcpy_s(this->surname, 99, surname);

		this->name = new char[100];
		strcpy_s(this->name, 99, name);

		this->patronymic = new char[100];
		strcpy_s(this->patronymic, 99, patronymic);

		adress = new char[100];
		strcpy_s(adress, 99, "Садовая,3");

		phone = new char[100];
		strcpy_s(phone, 99, "777 777 777");

		counterMarks = 0;
		counterCoursework = 0;
		counterExam = 0;

		for (int i = 0; i < counterMarks; i++)
			marks[i] = 0;

		for (int i = 0; i < counterCoursework; i++)
			coursework[i] = 0;

		for (int i = 0; i < counterExam; i++)
			exam[i] = 0;
	}

	Student(char* surname, char* name, char* patronymic, Date date)
	{
		SetShow(surname, name, patronymic, date, adress, phone);
	}

	Student(char* surname, char* name, char* patronymic, Date date, char* adress)
	{
		SetShow(surname, name, patronymic, date, adress, phone);
	}

	Student(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone)
	{
		SetShow(surname, name, patronymic, date, adress, phone);
	}

	Student(const Student& original)
	{
		surname = new char[100];
		strcpy_s(surname, 99, original.surname);

		name = new char[100];
		strcpy_s(name, 99, original.name);

		patronymic = new char[100];
		strcpy_s(patronymic, 99, original.patronymic);

		name = new char[100];
		strcpy_s(name, 99, original.name);

		adress = new char[100];
		strcpy_s(adress, 99, original.adress);

		phone = new char[100];
		strcpy_s(phone, 99, original.phone);

		counterMarks = original.counterMarks;
		counterCoursework = original.counterCoursework;
		counterExam = original.counterExam;

		for (int i = 0; i < counterMarks; i++)
			marks[i] = original.marks[i];

		for (int i = 0; i < counterCoursework; i++)
			coursework[i] = original.coursework[i];

		for (int i = 0; i < counterExam; i++)
			exam[i] = original.exam[i];
	}

	~Student()
	{
		if (surname != nullptr)delete[]surname;
		if (name != nullptr) delete[]name;
		if (patronymic != nullptr)delete[]patronymic;
		if (adress != nullptr)delete[]adress;
		if (phone != nullptr)delete[]phone;		
	}

	void SetDate(unsigned short day, unsigned short month, unsigned short year)
	{
		d.SetDay(day);
		d.SetMonth(month);
		d.SetYear(year);
	}

	void SetAdress(char* adress)
	{
		if (adress == nullptr)
			return;
		if (strlen(adress) < 1)
			return;

		if (this->adress != nullptr)
			delete[]this->adress;

		this->adress = new char[strlen(adress) + 1];
		strcpy_s(this->adress, strlen(adress) + 1, adress);
	}

	void SetPhone(char* phone)
	{
		if (phone == nullptr)
			return;
		if (strlen(phone) != 10)
			return;

		if (this->phone != nullptr) delete[] this->phone;
		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}

	void SetMark(int value)
	{
		if ((value < 1 || value>12) && counterMarks >= 5)
			return;

		marks.push_back(value);
		counterMarks++;
	}

	void SetCoursework(int value)
	{
		if ((value < 1 || value>12) && counterMarks >= 5)
			return;
		coursework.push_back(value);
		counterCoursework++;
	}

	void SetExam(int value)
	{
		if ((value < 1 || value>12) && counterMarks >= 5)
			return;
		exam.push_back(value);
		counterExam++;
	}

	const char* const GetAdress() const
	{
		return adress;
	}

	const char* const GetPhone() const
	{
		return phone;
	}

	void PrintStudent()
	{
		cout << "Фамилия " << surname << "\n";
		cout << "Имя: " << name << "\n";
		cout << "Отчество: " << patronymic << "\n";
		cout << "Дата рождения " << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear() << "\n";
		cout << "Адрес: " << adress << "\n";
		cout << "Телефон: " << phone << "\n";		
		cout << "\n";
	}

	void SetShow(const char* surname, const char* name, const char* patronymic, Date date, const char* adress, const char* phone)
	{
		SetSurname(this->surname);
		SetName(this->name);
		SetSurname(this->surname);
		SetPatronymic(this->patronymic);		
		SetAdress(this->adress);
		SetPhone(this->phone);
	}

	const char* const GetSurname() const
	{
		return surname;
	}

	const char* const GetName() const
	{
		return name;
	}

	const char* const GetPatronymic() const
	{
		return patronymic;
	}

	vector<int> GetMarks()
	{
		return marks;
	}

	vector<int> GetCoursework()
	{
		return  coursework;
	}

	vector<int> GetExam()
	{
		return exam;
	}

	bool operator > (Student& second)
	{
		if (this->GetSurname() > second.GetSurname())
		{
			return true;
		}
		return false;
	}

	bool operator < (Student& second)
	{
		if (this->GetSurname() < second.GetSurname())
		{
			return true;
		}
		return false;
	}

	Student& operator += (int marks)
	{
		SetMark(marks);
		return *this;
	}

	bool operator == (Student& second)
	{
		if (this->GetExam() == second.GetExam())
		{
			return true;
		}
		return false;
	}

	bool operator != (Student& second)
	{
		if (this->GetExam() != second.GetExam())
		{
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, Student& original)
	{
		original.PrintStudent();
		return os;
	}

	private:
	void SetSurname(char* surname)
	{
		this->surname = new char[100];
		strcpy_s(this->surname, 99, surname);
	}

	void SetName(char* name)
	{
		this->name = new char[100];
		strcpy_s(this->name, 99, name);
	}

	void SetPatronymic(char* patronymic)
	{
		this->patronymic = new char[100];
		strcpy_s(this->patronymic, 99, patronymic);
	}	
};

class Aspirant : public Student
{
	string theme;
  
public:
	Aspirant():Aspirant("No them", "No surname", "No name", "No patronymic")
	{		
	}

	Aspirant(string t, const char* surname, const char* name, const char* patronymic) : Student(surname, name, patronymic)
	{ 
		theme = t;
	}

	void SeTeme(string theme_)
	{
		theme = theme_;
	}

	string GetTheme() const
	{
		return theme;
	}

	void PrintAspirant()
	{
		PrintStudent();
		cout << "Тема кандидатской диссертации: \n";
		cout << theme << "\n";		
	}
};

int main()
{
	setlocale(0, "UKR");
	srand(time(0));
		
	Aspirant a ("Распространение сферически-симметричного пламени в газовзвесях частиц твердых горючих", "Василий", "Васильевич", "Васильев");
	a.PrintAspirant();
	cout << "\n\n";
}
