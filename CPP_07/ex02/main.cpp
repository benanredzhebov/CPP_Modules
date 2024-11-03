
#include "./Array.hpp"

#define MAX_VAL 750

int main(void)
{
	{
	// 	// Test 1: Default constructor
		std::cout <<"Test 1" << std::endl;
		Array<int> emptyArray;
		std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Test 2: Parameterized constructor
	std::cout <<"Test 2" << std::endl;
	Array<int> fibonacciArray(10);
	std::cout << "Try to print empty array: ";
	fibonacciArray.print();
	int a = 0, b = 1;
	for (unsigned int i = 0; i < fibonacciArray.size(); i++)
	{
		fibonacciArray[i] = a; // 0, 1, 1, 2, 3..
		int temp = a + b; // calculating the next Fibonacci number 2,3,5..
		a = b; // 1,2,3
		b = temp; //2,3,5
	}
	fibonacciArray.print();
	std::cout << std::endl << std::endl;

	{
		// Test 3: copy constructor
		std::cout <<"Test 3" << std::endl;
		Array<int> copiedArray(fibonacciArray); // Creating new array by copying the Fibonacci array
		copiedArray[0] = 100; // Modifies the first element of the copied array
		copiedArray.print();
		fibonacciArray.print(); // Prints original array to ensure it has not been modified.

	}
	std::cout << std::endl << std::endl;

	{
		// Test 4: Assignment operator
		std::cout <<"Test 4" << std::endl;
		Array<int> assignedArray;
		assignedArray = fibonacciArray;
		assignedArray[1] = 200;
		assignedArray.print();
		fibonacciArray.print();
	}
	std::cout << std::endl;

	//Test 5: Assignment operator
	std::cout <<"Test 5" << std::endl;
	try 
	{
		fibonacciArray[15] = 42; // Index is out of bounds
	} 
	catch (const Array<int>::OutOfRangeException& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
}
