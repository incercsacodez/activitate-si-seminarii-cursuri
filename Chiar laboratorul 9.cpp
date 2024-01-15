#include<iostream>
#include<string>

using namespace std;
//char* location;
	//char location[50];
	//char* location[100];
	//char locations[100][50];//static array of 100 static arrays,each having 50 
	//char** locations;
class DeliveryVan {



	string driver=" ";//dynamic array of chars
	string* locations=nullptr;
	int* noBoxes=nullptr;
	int noDeliveries=0;
	const float volume;
	const static int MAX_NO_BOXES;
	const static int MIN_NO_BOXES;
private:
	static int NO_DELIVERY_VANS;
public:


	void addDelivey(string location, int noBoxesForLocation) {

		int* newNoBoxes = new int[this->noDeliveries + 1];
		for (int i = 0; i < this->noDeliveries; i++)
		{
			newNoBoxes[i] = this->noBoxes[i];

		}
		newNoBoxes[this->noDeliveries] = noBoxesForLocation;
		//avoiding the memory leak
		this->noBoxes = newNoBoxes;
		delete[] this->noBoxes;


		string* newLocations = new string[this->noDeliveries + 1];
		for (int i = 0; i < this->noDeliveries; i++)
		{
			newLocations[i] = this->locations[i];
		}
		newLocations[this->noDeliveries] = location;
		delete[]this->locations;
		this->locations = newLocations;

		this->noDeliveries += 1;

	}
	void changeDriver(string newDriver) {
		this->driver = newDriver; 
	}

	DeliveryVan(string driverName, float vanVolume) :volume(vanVolume), driver(driverName) {

		DeliveryVan::NO_DELIVERY_VANS += 1;
	}
	~DeliveryVan() {
		cout << endl << "callingggg";
		delete[]this->noBoxes;
		delete[]this->locations;


	}
	DeliveryVan(const DeliveryVan& van):volume(van.volume), driver(van.driver) {

		//this->locations = van.locations;
		this->locations = new string[van.noDeliveries];
		this->noBoxes = new int[van.noDeliveries];
		for (int i = 0; i < van.noDeliveries; i++) {
			this->locations[i] = van.locations[i];
			this->noBoxes[i] = van.noBoxes[i];
		}
		this->noDeliveries = van.noDeliveries;
		DeliveryVan::NO_DELIVERY_VANS += 1;
	}
};

const int DeliveryVan::MAX_NO_BOXES=5;
const int DeliveryVan::MIN_NO_BOXES=1;
int DeliveryVan::NO_DELIVERY_VANS = 0;


int main() {
	DeliveryVan van1("john", 300);
	DeliveryVan van2("bob", 500);


}