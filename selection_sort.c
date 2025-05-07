#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void swap(uint32_t* x, uint32_t* y)
{
    uint32_t temp = *y;
    *y = *x;
    *x = temp;
}

void selection_sort(uint32_t* arr, uint32_t size)
{
    // Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.

    for (uint32_t step = 0; step < (size - 1); step++)
    {
        uint32_t min_idx = step;
        for (uint32_t i = step + 1; i < size; i++)
        {
            // Find the smallest value in the unsorted list
            if (arr[i] < arr[min_idx])
            {
                min_idx = i;
            }
        }

        // Move the smallest element to the sorted list
        swap(&arr[step], &arr[min_idx]);
    }
}

void print_array(uint32_t* arr, uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    uint32_t arr[] = { 5, 8, 4, 9, 7, 3, 1, 2, 6 };
    uint32_t arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorted: ");
    print_array(arr, arr_size);
    selection_sort(arr, arr_size);
    printf("Array after sorted: ");
    print_array(arr, arr_size);
    return 0;
}
