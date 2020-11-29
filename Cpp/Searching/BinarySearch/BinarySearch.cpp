#include <iostream>
#include <Windows.h>

/*
  Binary Search Algorithm:
    1. Divide the array into two halves. 0th index as Low, last index as High and a middle.
    2. Compare x with the middle element.
    3. If x matches with middle element, we return the mid index.
    4. Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
    5. Else (x is smaller) recur for the left half.

  Args:
    INPUT:
      const UINT32 arr:
        It's an array of integers.
      const UINT32 arr_size:
        It's the size of array being passed.
      const UINT32 x:
        It's the element to be searched in the array.
    OUTPUT:
      UINT32 index:
        It's the index of x found in array.

  Returns:
    TRUE:  Element found in the array
    FALSE: Element not found in the array
*/
BOOLEAN BinarySearch (
  const UINT32  *arr,
  const UINT32  arr_size,
  const UINT32  x,
  UINT32        &index
)
{
  if (arr == NULL) {
    std::cout << "Null pointer" << std::endl;
    return FALSE;
  }

  for (UINT32 low = 0, mid = 0, high = arr_size - 1; low <= high;) {
    mid = ((high - low) / 2) + low;

    if (x == arr[mid]) {
      index = mid;
      return TRUE;
    }
    else if (x < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return FALSE;
}

int main ()
{
  UINT32 arr[] = { 2,5,8,12,16,23,28,38,56,72,91,102,121,132,150 };
  UINT32 x;
  UINT32 Index;
  BOOLEAN Status;
  std::cout << "Binary Search: This program accepts a number and searches if it present in the aleady sorted array. If the number is found, it returns the index." << std::endl;
  std::cout << "The array elements are: ";
  for (UINT32 i = 0; i < sizeof(arr) / sizeof(*arr); i++)
  {
    std::cout << arr[i];
    if (i < (sizeof(arr) / sizeof(*arr)) - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
  std::cout << "Enter a number: ";
  std::cin >> x;
  Status = BinarySearch (arr, sizeof(arr) / sizeof(*arr), x, Index);
  if (Status)
    std::cout << x << " is found at index " << Index << std::endl;
  else
    std::cout << x << " is not found in the array" << std::endl;
}
