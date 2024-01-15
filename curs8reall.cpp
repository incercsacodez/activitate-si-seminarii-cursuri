
#include<iostream>
#include<string>
using namespace std;

//static attributes
//constant atributes
//copy constuctor
//overloading operators- = operator and others

class Student {
public:
	const int registrationNo;
private:
	string name = " ";
	int age;
	int* grades = nullptr;
	int noCourses = 0;
	const int birthYear;



	static int MIN_AGE;
	static int MAX_AGE;
	const static int DEFAULT_REG_NO;
	static int STUDENT_COUNTER;


public:
	void setAge(int value) {

		if (value >= Student::MIN_AGE && value <=Student::MAX_AGE)
		{
			this->age = value;
		}
		else {
			throw exception("Wrong value for age");
		}
	}


	void setName(const char *newName) {
		this->name = string(newName);

	}
	//the constant is initialized with a default value from a static
	Student():registrationNo(Student::DEFAULT_REG_NO),birthYear(0) {
		STUDENT_COUNTER += 1;


	}
	//the constant is initialized with a default value from a static attribute
	Student(string name) :registrationNo(Student::STUDENT_COUNTER),birthYear(0) {
		STUDENT_COUNTER += 1;
	}
	//the constant is initialized with a default value recived
	Student(string name, int id) :registrationNo(id),birthYear(0) {
		this->name = name;
		STUDENT_COUNTER += 1;
	}
	//Student(int id, string name, int ageValue) :registrationNo(id),age(ageValue) {
	//	this->name = name;
	//	//is tedundant
	//	//this ->age=ageValue
	//}
	Student(int id, string name, int age, int birthYear) : registrationNo(id),
		name(name), age(age), birthYear(birthYear) {

		STUDENT_COUNTER += 1;
	}
	//don't use the constructor initialization list-> it will do a shallow copy 
	Student(int id, string nameValue, int ageValue) :registrationNo(id), age(ageValue),name(nameValue), birthYear(0) {
		//this->name = name;
		//is tedundant
		//this ->age=ageValue
		STUDENT_COUNTER += 1;
	}
	
};



int Student::MIN_AGE = 10;
int Student::MAX_AGE = 90;
const int Student::DEFAULT_REG_NO = 0;
int Student::STUDENT_COUNTER = 1;


class GradeBook {

	string courseName=" ";
	int* grades=nullptr;
	int noGrades=0;
public:
	GradeBook(string name) :courseName(name) {

	}
	void addGrade(int grade) {
		int* newArray = new int[this->noGrades+1];
		for(int i=0;i < this->noGrades;i++)
		{ 
			newArray[i] = this->grades[i];
		}
		newArray[this->noGrades] = grade;
		this->noGrades += 1;
		if (this->grades != nullptr) {
			delete[] this->grades;
		}

		this->grades = newArray;
	}

	void print() {
		cout << endl << "Grades for " << this->courseName;
		for (int i = 0; i < this->noGrades; i++)
		{
			cout << this->grades[i] << " ";
		}
	}

	~GradeBook() {
		delete[] this->grades;
	}

	//class copy constructor
	GradeBook(const GradeBook& object):courseName(object.courseName) {
		this->grades = new int[object.noGrades];
		for (int i = 0; i < object.noGrades; i++)
		{
			this->grades[i] = object.grades[i];
		}
		this->noGrades = object.noGrades;
	}
	//you don't need the copy constructor for pointers only for objects
	//MANDATORY
};

int main() {

	Student student;
	Student alice(1, "Alice", 35);
	Student john(2, "john", 21, 2000);
	cout << endl << "John id is  " << john.registrationNo;

	Student bob("Bob");
	cout<< endl << "Bob id is  " << bob.registrationNo;

	GradeBook oop("OOP");
	oop.addGrade(10);
	oop.addGrade(10);
	oop.addGrade(9);
	oop.print();

}
