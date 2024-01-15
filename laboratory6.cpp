#include <iostream> 

void printArray(int* arrayAddr, int noElements) {
	std::cout << std::endl << "the values are: ";
	for (int i = 0; i < noElements; i++) {
		std::cout << arrayAddr[i] << "";
	}
}

//it will not work 
//wrong
void resizeArray(int* initialArray, int noElements, int newSize)
{
	int* temp = new int[newSize];
	for (int i = 0; i < noElements; i++) {
		temp[i] = initialArray[i];
	}
	delete[] initialArray;
	initialArray = temp;
	noElements = newSize;
}

void resizeArrayWithPointers(int** addrInitialArray, int* addrnoElements, int newSize)
{
	int* temp = new int[newSize];
	for (int i = 0; i < *addrnoElements; i++)
	{
		temp[i] =(*addrInitialArray)[i];
	}
	delete[](*addrInitialArray);
	*addrInitialArray = temp;
	*addrnoElements = newSize;
}
void resizeArrayWithReferences(int* initialArray, int noElements, int newSize)
{
	int* temp = new int[newSize];
	for (int i = 0; i < noElements; i++) {
		temp[i] = initialArray[i];
	}
	delete[] initialArray;
	initialArray = temp;
	noElements = newSize;
}
	
int main() {

	//static arrays
	int staticArray[5];
	int anotherStatic[] = { 10, 20,30 };

	//dynemic array
	//is just a pointer there is no array here
	

	//1. define the pointer to the 1st value in the array
	int* dynamicArray = nullptr;
	//2.create the array
	int noElements = 5;
	dynamicArray = new int[noElements];//5 x int in heap

	//3. init the value
	for (int i = 0; i < noElements; i++) {
		dynamicArray[i] = (i + 1);
	}
	//before resizing ask if you still need the previous values
	//no
	//you can delete the previous one

	//delete[] dynamicArray;


		//std::cout << std::endl << "the array is"<<dynamicArray;
		//printArray(dynamicArray, noElements);
	//resize the dynemic array

		//dynamicArray = new int[10];

	//yes

	//create the new array
	int* newArray = new int[10]; 
	//copy values from the previous one
	for (int i = 0; i < noElements; i++) {

		newArray[i] = dynamicArray[i];
	}

	delete[] dynamicArray;
	//copy the adress of the new array
	dynamicArray = newArray;
	//update no elements
	noElements = 10;

	std::cout << std::endl << "the new resized array in heap is" << dynamicArray;
	printArray(dynamicArray, noElements);

	//resizeArray(dynamicArray, noElements, 20);
	resizeArrayWithPointers(&dynamicArray, &noElements, 20);
	printArray(dynamicArray, noElements);
	resizeArrayWithReferences(dynamicArray, noElements, 20);
}