#include <iostream>

/* 
Linear Search Algorithm:
  1. Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
  2. If x matches with an element, return the index.
  3. If x doesn’t match with any of elements, return -1.
*/

int LinearSearch(int *arr, int arr_size, int x)
{
	for (int i = 0; i < arr_size; i++)
	{
		if (x == arr[i])
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 2,5,8,12,16,23,28,38,56,72,91,102,121,132,150 };
	int x;
	int Index;
	std::cout << "Linear Search: This program accepts a number and searches if it present in the array. \
	If the number is found it returns the index otherwise -1." << std::endl;
	std::cout << "The array elements are: ";
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		std::cout << arr[i];
		if (i < (sizeof(arr) / sizeof(int)) - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << "Enter a number: ";
	std::cin >> x;
	if ((Index = LinearSearch(arr, sizeof(arr) / sizeof(int), x)) == -1)
		std::cout << x << " is not found in the array" << std::endl;
	else
		std::cout << x << " is found at index " << Index << std::endl;
}