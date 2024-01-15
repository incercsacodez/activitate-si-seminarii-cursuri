#include<iostream>
#include<string>
using namespace std;

//today topics
//constant and static attributes
//memory leaks and the destuctor
//copy constructor
//shallow copy vs deep copy
//remember enums
//shadowing
enum ProgramType{UNDERGRADUATE=10,MASTER=20,PHD=30};

class Student {
	string name=" ";
	ProgramType program=UNDERGRADUATE;  //Undergraduate, master, phd

	int age;
	int* grades=nullptr;
	int noGrades=0;

public:

	static int minAge;
	static int maxAge;

	
public:
	void printInfo() {
		cout << endl << "------------------------";
		cout << endl << "Name: " << this->name;
		cout << endl << "ProgramType" <<this-> program;
		cout << endl << "ProgramName" << this->getProgramName();
		if (this->grades != nullptr) {
			cout << endl << "Student grades";
			for(int i=0; i<noGrades;i++)
			{
				cout << endl << this->grades[i]<<" ";
			}
		}
	}
public:
	string getProgramName() {

		switch (this->program)
		{
		case UNDERGRADUATE:
			return "Undergraduate";
		case MASTER:
			return "Master";
		case PHD:
			return "PHD";
		}
	}
	ProgramType getProgramType() {
		return this->program;
	}

	void setGrades( int* someGrades, int noRecivedGrades) {
		if (someGrades == nullptr) {
			throw exception("No grades");
		}
		//shallow copy
		//this->grades = someGrades;
		//deep copy
		//avoid the memory leack
		if (this->grades != nullptr) {
			delete[] this->grades;
		}// we delete
		this->noGrades = noRecivedGrades;
		this->grades = new int[noRecivedGrades];
		for(int i=0; i<noRecivedGrades; i++)
		{
			this->grades[i] = someGrades[i];
		}
		this->noGrades = noRecivedGrades;
	}

	void retakeExam(int newGrade, int index) {
		if (index<0 or index>=this->noGrades)
		{
			throw exception("worong");
		}
		this->grades[index] = newGrade;
	}


	void setName(string name)
	{
		this->name = name;
	}

	void setAge(int newAge) {
		
		if (minAge < minAge or maxAge>90)
		{
			throw exception("Wrong age");
		}
		this->age = newAge;
	}
	Student(string name, ProgramType program, int* grades, int noGrades) {
		this->name = name;
		this->program = program;

		this->setGrades(grades, noGrades);
	}
	//the class destructor

	~Student() {
		//we release the space from Heap where objects store data
		if (this->grades != nullptr) {
			delete[] this->grades;

		}
	}

	Student() {

	}
};

 int Student::minAge = 10;
 int Student::maxAge = 90;

int main() {

	//default constructor
	Student student; 
	student.printInfo();
	int grades[] = { 10,10,9 };
	int noGrades = 3;

	student.setGrades(grades, noGrades);
	 student.printInfo();
	 Student alice("alice", ProgramType::UNDERGRADUATE, grades, noGrades);
	 alice.printInfo();
	 student.setName("john");
	 student.retakeExam(10, 2);
	 student.printInfo();
	 alice.printInfo();

	 cout << endl << Student::minAge;

	
}

/////MODEL TEST OOP WOOPPP

//#include<iostream>
//sa se implementeze o clasa Spital cf urmatoarelor cerinte
//Clasa are cel putin urmatoarele atribute
//cod implementare fiscala
//se atribuie valoare la pointer, valoare de tip sir de caractere
//un nume sir de caractere
//adresa sir de caractere
//medici un vector de valori string alocat dinamic
//nomedici
//no spitale va retine nr de spitale obiecte tip spital static int
//se vor implementa constuctor fara parametrii
//constructor cu toti parametrii
//constructor de copiere
//destructor
//supraincarcare operator =
//supraincarcare operatori de cititire si scrie din / in consola
//supraincarcare operator de indexare returneaza medicul de pe o pozitie data
//atat in mod scriere cat si in mod cititire
//supraincarcare operator negatie
//cast implicit int nr de spitale instantiat creeate
//metode de get si set
//cel putin unul din atributele de tip sir de caractere trb sa fie char*
//toti membrii trebuie sa fie private
//
//using namespace std;
//
//class Spital {
//
//	const string cif;
//	char* nume;
//	string adresa;
//	string* medici;
//	int noMedici;
//	static int noSpitale;
//public:
//	Spital():cif("" ){
//		this->nume = nullptr;
//		this->adresa = " ";
//		this->medici = nullptr;
//		this->noMedici = 0;
//	}
//	Spital(string cif, const char* _nume, string _adresa, const string* _medici,int _noMedici ):cif(cif) , adresa(_adresa),noMedici(_noMedici)
//	{
//		if (_nume != nullptr) {
//			this->nume = new char[strlen(_nume) + 1];
//			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
//		}
//		else
//			this->nume = nullptr;
//		this->medici = new string[_noMedici];
//		for (int i = 0; i < _noMedici; i++)
//		{
//			this->medici[i] = _medici[i];
//		}
//		Spital::noSpitale++;
//
//	}
//	Spital& operator= (Spital& s)
//	{
//		if (this == &s)
//			return *this;
//		delete[] this->nume;
//		this->nume = new char[strlen(s.nume) + 1];
//		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
//
//
//		delete[] this->medici;
//		this->medici = new string[s.noMedici];
//		this->medici = new string[s.noMedici];
//		for (int i = 0; i < s.noMedici; i++)
//			this->medici[i] = s.medici[i];
//		this->adresa = s.adresa;
//		return *this;
//
//	}
//
//	void setNume(const char* _nume) {
//		if (_nume != nullptr)
//		{
//			delete[] this->nume;
//			this->nume= new char[strlen(_nume) + 1];
//			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
//		}
//		else
//			this->nume = nullptr;
//	}
//	
//	void setAdresa(string _adresa) { this->adresa = _adresa; }
//
//
//	Spital(Spital& s) :Spital(s.cif, s.nume, s.adresa, s.medici, s.noMedici)
//	{
//
//	}
//
//	~Spital()
//	{
//		delete[] this->nume;
//		delete[] this->medici;
//
//	}
//
//};
//
//int Spital::noSpitale = 0;
//
//int main() {
//
//	return 0;
//}

