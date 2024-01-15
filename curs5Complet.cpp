#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Student {

	char name[100];
	bool hasScholarship;
	int age;

public:
	//class constructor
	Student(const char* name, int age, bool hasScholarship) {
		this->setAge(age);
		this->setScholarship(hasScholarship);
		this-> setName(name);

	}

	int getAge() { // recives by default the adress of the calling obj

		return this->age;  // the pointer is named this

	}

	bool gethasScholarship() {

		return this->hasScholarship;

	}
	//!!!! IT'S NOT OK  
	//char* getName() {
	//	return this->name;
	//}

	string getNameValue() {

		return string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy = new char[strlen(this->name + 1)];
		strcpy_s(nameCopy, strlen( this->name)+1 ,this->name);

		return nameCopy;

	}
	//write access 
	void setAge(int value) {
		//validate the input
		if (value >= 10 && value <= 100) {
			this->age = value;
		}
		else {
			//throw "wrong value for age";
			throw exception("wrong value for age");
		}
	}

	void setScholarship(bool value) {

		this->hasScholarship = value;
	}

	void gainScholarship() {
		this->hasScholarship = true;
	}

	void losesScholarship() {
		this->hasScholarship = false;
	}
private:
	void setName(const char* value) {
		if (strlen(value) > 99) {
			throw exception("value is to long");
		}
		strcpy_s(this->name, 99, value);
	}
};

class Faculty {

	char* name;
	string adress;
};

int main()
{
	string message;
	message = "Course 05";
	message = "hello" + message;

	cout << endl << message;
	cout << endl << "the lenght of the message is" << message.length();

	Student student("alice",20,true);
	Student studentJohn("john", 12, false);
	//student.age = 21;
	//int studentAge = student.age;
	message = "the end";
	int studentAge = student.getAge();
	studentAge = studentJohn.getAge();

	cout << endl << "Alice age is" << student.getAge();
	cout << endl << "Alice name is" << student.getNameValueAsPointer();

	//student.setAge(-21);

	//studentJohn.setName("jhon");
	studentJohn.setAge(21);
	studentJohn.gainScholarship();

	cout << endl << "student name is" << studentJohn.getNameValue();




}