#include <iostream>

/*
Binary Search Algorithm:
  1. Divide the array into two halves. 0th index as Low, last index as High and a middle.
  1. Compare x with the middle element.
  2. If x matches with middle element, we return the mid index.
  3. Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
  4. Else (x is smaller) recur for the left half.
*/

int BinarySearch(int *arr, int arr_size, int x)
{
	int low, mid, high;
	low = 0;
	high = arr_size;

	while (low < high)
	{
		mid = (high - low) / 2 + low;
		if (x == arr[mid])
			return mid;
		else if (x < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	int arr[] = { 2,5,8,12,16,23,28,38,56,72,91,102,121,132,150 };
	int x;
	int Index;
	std::cout << "Binary Search: This program accepts a number and searches if it present in the array. \
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
	if ((Index = BinarySearch(arr, sizeof(arr) / sizeof(int), x)) == -1)
		std::cout << x << " is not found in the array" << std::endl;
	else
		std::cout << x << " is found at index " << Index << std::endl;
}
