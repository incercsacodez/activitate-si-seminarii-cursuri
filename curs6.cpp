#include<iostream>
#include<string>
#include<string.h>
using namespace std;


class Student {
	//you can choose your own defaults- DO IT 
	char name[100]="-";
	bool hasScholarship=false;
	int age=0;
	int* grades=nullptr;
	int noGrades=0;

public:
	//public interface
	//class constructor
	Student(const char* name, int age, bool hasScholarship) {
		this->setAge(age);
		//if (hasScholarship) {
		//	this->gainScholarship();
		//} 
		//else {
		//	this->losesScholarship();
		//}
		hasScholarship ? this->gainScholarship() : this->losesScholarship();
		this->setName(name);

	}
	//overloading
	//JUST FOR THIS COURSE
	//IT MIGHT CREATE CONFUSION WITH THE PREVIOUS
	Student(const char* name, bool hasScholarship, int age ) {
		this->setAge(age);
		//if (hasScholarship) {
		//	this->gainScholarship();
		//} 
		//else {
		//	this->losesScholarship();
		//}
		hasScholarship ? this->gainScholarship() : this->losesScholarship();
		this->setName(name);

	}

	Student(const char* name, int age) {
		this->setAge(age);
		this->hasScholarship = false;
		this->setName(name);

		

		}
	//default constructor
	//made it private because allows students with inconsistent data
private:
	Student() {
		this->setName("Jhon Doe");
		this->hasScholarship = false;
		this->age = 0;

	}
public:
	//WE CCHOOSE NOT TO IMPLEMENT IT BECAUSE WE 
	// CONSIDER THAT NAME AND AGE ARE MANDATORY
	//Student(const char* name) {
	//	//this->setAge(0);
	//	this->age = 0;
	//	this->hasScholarship = false;
	//	this->setName(name);
	//}

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
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);

		return nameCopy;

	}
	//write access 
	//void setAge(int value{
	//if(value>=10 && value<=100){
	//this->age=value;}
	//else { throw exception ("wrong value for age")}
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

public:
	void printInfo() {

		cout << endl << "-------------------------";
		cout << endl << "Name" << this->getNameValue();
		cout << endl << "age" << this->age;
		cout << endl << "Has scholarship" << (this->hasScholarship ? "true" : "false");
		if (this->noGrades !=  0)
		{
			cout << endl << "grades";
			for (int i = 0; i <= noGrades; i++) {
				cout << this->grades[i] << " ";
			}
	}
	}

};
//overloading

//defining multiple methods with the same name but with different argument list 
int addNumbers(int a, int b) {
	return a + b;
}

int addNumbers(int a, int b, int c) {
	return a + b + c;
}

class Faculty {
	string name;
	string adress;
public:
	/*Faculty(string name, string adress)
	{
		this->name = name;
		this->adress = adress;
	}*/

	Faculty() {

	}
};

void incrementCounter(int value) {
	value += 1;
}
void incrementCounterWithPointer(int* pointerToCounter)
{
	*pointerToCounter += 1;
}
void incrementCounterWithReferences(int  &value) {
	value += 1;
}
int main() {
	int resault = addNumbers(10, 20);
	resault = addNumbers(10, 20, 30);
	//testing the constructor
	Student alice("Alice", true, 21);
	Student john("John", 21, false);
	Student bob("bob", 20);
	alice.printInfo();
	john.printInfo();
	bob.printInfo();
	alice.gethasScholarship();
	bob.gethasScholarship();
	//Student vader("Vader");
	//vader.printInfo();

	//Student vader;
	Faculty csie;

	//vader.printInfo();

	int counter = 0;
	//increment
	counter += 1;

	cout << endl<< "the counter is" << counter;

	incrementCounter(counter);
	cout << endl << "the counter is" << counter;

	incrementCounterWithPointer(&counter);
	cout << endl << "the counter is" << counter;

	incrementCounterWithReferences(counter);
	cout << endl << "the counter is" << counter;
}	

