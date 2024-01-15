#include <iostream>
#include<string>
using namespace std;

enum UserType{ADMIN=1, MANAGER, CLIENTI=50};
enum DiscountType{NONE, MINIMUM=10, AVERAGE=15, BLACK_FRIDAY=50};
class Product {
private:
	string name= "";
	char* description=nullptr;
	float price=0;
	int availableStock=0;
	DiscountType discount=DiscountType::NONE;
	bool isAvailable=false;

	int* montlySoldItems=nullptr;// items sold each month since we open the shop or we added  the Product
	int noMonths=0;

public:
	string getName() {
		return this->name;
	}

	int* getMonthlySoldItems() {
		//dont't
		//return this-> monthlySoldItems
		if (this->montlySoldItems == nullptr && this->noMonths == 0) {

			return nullptr;
		}
		int* dataCopy = new int[this->noMonths];
		for (int i = 0; i < this->noMonths; i++) {
			dataCopy[i] = this->montlySoldItems[i];
		}

	}

	int getNoMonths() {

		return this->noMonths;
	}

	int getStock() {
		return this->availableStock;
	}

	bool IsAvailable() {
		return this->isAvailable;
	}
public:
	void printInfo() {
		cout << endl << "----------------------";
		cout << endl << "Name: " << this->name;
		if (this->description != nullptr) {
			cout << endl << "Description " << this->description;
		} 
		cout << endl << "Price " << this->price;
		cout << endl << "stock " << this->availableStock;
		cout << endl << "Discount " << this->discount << "%";
		cout << endl << (this->isAvailable ? "Is available" : "You can make a pre-order");
		if (this->montlySoldItems != nullptr);
		{
			cout << endl << "previous sold items ";
			for (int i = 0; i < this->noMonths; i++) {
				cout << this->montlySoldItems[i] << " ";
			}
		}
	}

	void setName(string name) {
		if (name.length() < 2)
		{
			throw exception("Wrong name, too short");
		}
		this->name = name;
	}

	void setPrice(float newPrice) {
		if (newPrice <= 0) {
			throw exception("NOT OK");
		}
		this->price = newPrice;
	}

	void setDescription(const char* newDescription) {
		if (strlen(newDescription) < 5) {
			throw exception("Description too short");
		}
		//this generates a memory leack
		//DON"T DO THIS
		this->description = new char[strlen(newDescription) + 1];
		strcpy_s(this->description, strlen(newDescription) + 1, newDescription);
		 }
	
	void setStock(int newStock) {
		if (availableStock < 0)
		{
			throw exception("Wrong value inserted");
		}
		this->availableStock=newStock;
		if (this->availableStock = 0) {

			this->isAvailable = false;
		}
		else {
			this->isAvailable = true;
		}
	}
	void setDiscount(DiscountType discount) {
		this->discount = discount;
	}

	void setPreviousMonthsValues(const int* backupData, int noValues)
	{
		if (backupData == nullptr); {
			throw exception("no imput values");
			
		}
		//we generate another memory leack
		this->montlySoldItems = new int[noValues];
		for (int i = 0; i < noValues; i++)
		{
			this->montlySoldItems[i] = backupData[i];
		}

		//don't forget
		this->noMonths = noValues;
	}
	public:
		Product(string name, float price, int stock) {
			this->setName(name);
			this->setPrice(price);
			this->setStock(stock);

		}
	Product(string name, const char * description, float price ,int stock)
	{
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
	}
	Product(string name, const char* description, float price, int stock, DiscountType discount)
	{
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
		this->setDiscount(discount);
	}

	Product(string name, const char* description, float price, int stock, 
		DiscountType discount, const int* priviousData, int noMonths)
	{
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
		this->setDiscount(discount);
		this->setPreviousMonthsValues(priviousData, noMonths);

	}
};

class Users {

	string userName;
	string passWord;

	//int numericType;// 1 is adim, 2 is manager, 3 is marketing, 4 is client
	//string stringType;//"admin", "manager", "marketing", "clienti", "ADMIN", "admin"

	UserType type;


};

class ShoppingCart {

};

class Order {



};



int main() {

	//Product product;
	//Product anotherProduct;



	/*product.printInfo();
	product.setName("Laptop");
	product.setDescription("gaming Laptop");
	product.setPrice(3500);
	product.setStock(15);
	product.setDiscount(DiscountType::BLACK_FRIDAY);
	product.printInfo();*/

	Product laptop("asus M300", 3500, 25);

	laptop.printInfo();

	Product gamingLaptop("asussus", "Gaming laptop funny", 4200, 10);
	gamingLaptop.printInfo();

	Product gamingLaptopSale("asussus", "Gaming laptop funny", 4200, 10, DiscountType ::BLACK_FRIDAY);

	gamingLaptopSale.printInfo();

	int previousData[] = { 6,10,20,12 };
	int noValues = 4;

	Product smartphone("X34", "THE  best PHONE", 2500, 16, DiscountType::MINIMUM, previousData, noValues);
	smartphone.printInfo();
	//Order order;




}