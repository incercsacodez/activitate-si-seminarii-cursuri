#include<iostream>
using namespace std;

class SuperStudent {
//class members are private by default
	//encapsulation
	char name[100];   // name is a char asterix
	int age;
	bool hasScholarship;

};

struct Student
{
	char name[100];   // name is a char asterix
	int age;
	bool hasScholarship;
	//int* noGrades;
	//int* grades;
}; 

Student initStudent(const char name[],const int age,const bool hasScholarschip)
{
	Student student;
	student.age = age;
	student.hasScholarship = hasScholarschip;
	strcpy_s(student.name, name);

	return student; 
}

void printStudent(Student student)
{
	cout << endl << "student name :" << student.name;
	cout << endl << "student age :" << student.age;


	// if(student.hasScholarship)
	//"true"
	//else
    //false
	cout << endl << "student has scholarship :" << (student.hasScholarship ? "true" : "false");


}





int main() {
	//data for only 1 student
	char studentName[100];
	int age;
	bool hasScholarship;

	//data for 1000 students
	const int noStudent = 1001;
	char* studentNames[noStudent];

	//char studentNames[1000][100];
	int studentAges[noStudent];
	bool studentScholarships[noStudent];
	Student student;

	Student students[noStudent]; // students is Student *
	char initialName[] = "Jhon";
	student = initStudent(initialName, 21, true);
	printStudent(student);

	//objects
	SuperStudent superStudent;
	//superStudent.age = -23;
	
} 