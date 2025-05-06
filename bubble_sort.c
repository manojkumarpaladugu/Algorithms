#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void bubble_sort(uint8_t* arr, uint32_t size)
{
    // Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.

    for(uint32_t step = 0; step < (size - 1); step++)
    {
        bool swapped = false;
        for(uint32_t i = 0; i < ((size - step) - 1); i++)
        {
            // After each iteration, move the largest element to the end
            if (arr[i] > arr[i + 1])
            {
                uint32_t temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }

        // If not swapped, the array is already sorted
        if (swapped == false)
        {
          break;
        }
    }
}

void print_array(uint8_t* arr, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    uint8_t arr[] = { 5, 8, 4, 9, 7, 3, 1, 2, 6 };
    printf("Array before sorted: ");
    print_array(arr, sizeof(arr));
    bubble_sort(arr, sizeof(arr));
    printf("Array after sorted: ");
    print_array(arr, sizeof(arr));
    return 0;
}
