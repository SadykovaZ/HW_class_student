#include<iostream>
using namespace std;
class student
{
private:
	char *name;
	bool sex;
	int age;
	int *grades;
	int size = 1;

public:
	student(const char *h_name, bool h_sex, int h_age) {
		name = new char[strlen(h_name) + 1];
		strcpy_s(name, strlen(h_name) + 1, h_name);
		sex = h_sex;
		age = h_age;
		grades = new int(5);
	}
	void info()
	{
		std::cout << "name: " << name << "\nsex: " << sex << "\nage: " << age << endl;
		cout << "grades: ";
		for (int i = 0; i < size; i++)
		{
			cout << grades[i] << " ";
		}
		cout << endl;
	}
	void set_name(const char *h_name)
	{
		delete[] name;
		name = new char[strlen(h_name) + 1];
		strcpy_s(name, strlen(h_name) + 1, h_name);
	}
	void set_sex(bool n_sex)
	{
		sex = n_sex;
	}
	void set_age(int n_age)
	{
		age = n_age;
	}
	void set_grades(int *n_grades, int size)
	{
		delete[] grades;
		grades = new int[size];
	}
	void addGrade()
	{
		
		int *newGrades = new int[size + 6];
		for (int i = 0; i < size; i++)
		{
			newGrades[i] = grades[i];
		}
		
		cout << "Enter new grade: ";
		cin>>newGrades[size];
		delete[] grades;
		size++;
		grades = newGrades;
	}
	char* get_name() {
		return name;
	}
	bool get_sex() {
		return sex;
	}
	int get_age() {
		return age;
	}
	int get_grades()
	{
		return *grades;
	}
	~student() {
		delete[] name;
		delete[] grades;
	}
};
void main()
{
	student s("Peter", 0, 15);
	s.info();
	while (true)
	{
		s.addGrade();
		s.info();
	}
	system("pause");
}