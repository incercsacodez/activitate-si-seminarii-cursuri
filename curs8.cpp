#include <iostream>
#include<string>

using namespace std;

class Product {

	char* name=nullptr;
	char manufacturer[50]=" ";
	float price = 0;;
	int* soldItemsPerMonth=nullptr;
	int noMonths=0;
public:
	static int MIN_NAME_LENGHT ;
	static float MIN_PRICE ;
	static float LUXURY_LIMIT;
	static int NO_LUXURY_PTODUCTS;

public:
	Product(const char* name, const char* manufacturer,float price, const  int* previousDta, int noRecords) {

		this->setName(name);
		this->setManufacturer(manufacturer);
		this->setPrice(price);
		this->setData(previousDta, noRecords);
}
	Product(const char* name, const char* manufacturer, float price) {
		this->setName(name);
		this->setManufacturer(manufacturer);
		this->setPrice(price);

	}

	void setName(const char* newName) {
		//validate
		if (newName == nullptr or strlen(newName)<Product::MIN_NAME_LENGHT )
		{
			throw exception("Name missing");
		}
		else {
			//avoid the memory leack
			if (this->name != nullptr)
			{
				delete[] this->name;
			}



			//we create a deep copy initializing a new space in heap
			//we create a new array
			this->name = new char[strlen(newName) + 1];
			//we copy the value
			strcpy_s(this->name, strlen(newName) + 1, newName);
		}

	}



	void setManufacturer(const char* newProducer)
	{//we validate 
		
	
		if (newProducer == nullptr or strlen(newProducer)	< Product::MIN_NAME_LENGHT )
		{
			throw exception("Too short");
		}
		else {
			
			// we can't create memory leacks with static arrays
			strcpy_s(this->manufacturer, strlen(newProducer) + 1, newProducer);

		}


	}

	void setPrice(float newPrice) {

		if (newPrice < Product::MIN_NAME_LENGHT) {
			throw exception("Wrong price");
		}
		else {  
			if(price<Product::LUXURY_LIMIT&&newPrice>Product::LUXURY_LIMIT)
			{
				Product::NO_LUXURY_PTODUCTS += 1;
			}else 
				if (price>Product::LUXURY_LIMIT && newPrice<Product::LUXURY_LIMIT)
				{
					Product::NO_LUXURY_PTODUCTS -= 1;
				}
				

			this->price = newPrice;
		}
	}
	void setData(const int* previousDta, int noRecords) {
		//avoid the memory leack
		if (this->soldItemsPerMonth != nullptr)
		{
			delete[] this->soldItemsPerMonth;
		}



		this->soldItemsPerMonth = new int[noRecords];
		for (int i = 0; i < noRecords; i++) {
			this->soldItemsPerMonth[i] = previousDta[i];
		}
		this->noMonths = noRecords;
	}

	//class destructor
	~Product() {
		cout << endl << "the product destructor";
		if (this->name != nullptr) {
			delete[] this->name;
		}

		delete[] this->soldItemsPerMonth;
	}

};
float Product::MIN_PRICE = 1;
int Product::MIN_NAME_LENGHT = 2;
float Product::LUXURY_LIMIT = 10000;
int Product::NO_LUXURY_PTODUCTS = 0;


int main() {

	cout << endl << "minimum lenght" << Product::MIN_NAME_LENGHT;

	int previousData[] = { 5,23,10,7 };
	int noMonths = 4;
	Product laptop("X4 GAMING", "ASUS", 2400, previousData, noMonths);
	Product smartphone("s2000", "samsung", 3400);

	Product* pointerToProduct = new Product("test", "test again", 1000);
	delete pointerToProduct;
	cout << endl << "After deleting test";


}
