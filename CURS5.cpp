#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Student {

	char name[100];
	bool hasScholarship;
	int age;

public:
	int getAge() { // recives by default the adress of the calling obj

		return this->age;  // the pointer is named this

	}

	bool gethasScholarship() {

		return this->hasScholarship;

	}
	//!!!! IT'S NOT OK  
	char * getName() {
		return this->name;
	}

	string getNameValue() {

		return string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy= new char[strlen(this->name+1)];
		strcpy(nameCopy, this->name);

		return nameCopy;

	}
	//write access 
	void setAge() {
		//validate the input
		if (value >= 10 && value <= 100) {
			this->age = value;
		}
		else {
			throw "wrong value for age";
		}
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

	Student student;
	Student studentJohn;
	//student.age = 21;
	//int studentAge = student.age;
	message = "the end";
	int studentAge = student.getAge();
	studentAge = studentJohn.getAge();

	cout << endl << "Alice age is" << student.getAge();
	cout << endl << "Alice name is" << student.getName();

	student.setAge(-21);

	


}