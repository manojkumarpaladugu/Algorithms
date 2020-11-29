#include <iostream>
#include <Windows.h>

/* 
  Linear Search Algorithm:
    1. Start from the leftmost element of arr[] and one by one compare x with each element of arr[]

  Args:
    INPUT:
      UINT32 arr:
        It's an array of integers.
      UINT32 arr_size:
        It's the size of array being passed.
      UINT32 x:
	    It's the element to be searched in the array.

	OUTPUT:
	  UINT32 index:
	    It's the index of x found in array.

  Returns:
    TRUE:  Element found in the array
    FALSE: Element not found in the array
*/
BOOLEAN LinearSearch(
  UINT32* arr,
  UINT32  arr_size,
  UINT32  x,
  UINT32& index)
{
  if (arr == NULL) {
    std::cout << "Null pointer" << std::endl;
    return FALSE;
  }

  for (UINT32 i = 0; i < arr_size; i++) {
    if (x == arr[i]) {
      index = i;
      return TRUE;
    }
  }

  return FALSE;
}

int main()
{
  UINT32 arr[] = { 2,5,8,12,16,23,28,38,56,72,91,102,121,132,150 };
  UINT32 x;
  UINT32 Index;
  BOOLEAN Status;
  std::cout << "Linear Search: This program accepts a number and searches if it present in the array. If the number is found it returns the index." << std::endl;
  std::cout << "The array elements are: ";
  for (UINT32 i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
    std::cout << arr[i];
    if (i < (sizeof(arr) / sizeof(*arr)) - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
  std::cout << "Enter a number: ";
  std::cin >> x;
  Status = LinearSearch(arr, sizeof(arr) / sizeof(*arr), x, Index);
  if (Status)
    std::cout << x << " is found at index " << Index << std::endl;
  else
    std::cout << x << " is not found in the array" << std::endl;
}
