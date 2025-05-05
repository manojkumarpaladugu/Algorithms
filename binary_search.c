#include <stdio.h>
#include <stdint.h>

uint32_t binary_search(uint8_t arr[], uint32_t size, uint32_t target)
{
    // Pre-requisite: Binary search requires array to be sorted in ascending order.
    uint32_t found_idx = -1;
    uint32_t first_idx =0;
    uint32_t last_idx = size - 1;
    
    // Repeat until the first and last pointers meet each other
    while(first_idx <= last_idx)
    {
        // Divide the array into two halves
        uint32_t number_of_elements = last_idx - first_idx;
        uint32_t middle_idx = first_idx + (number_of_elements / 2);
        printf("first: %d, mid = %d, last: %d\n", first_idx, middle_idx, last_idx);

        // Return if the target is found at the middle index
        if (arr[middle_idx] == target)
        {
            found_idx = middle_idx;
            break;
        }
        // Jump to right half, if the target is greater than the middle element
        else if (target > arr[middle_idx])
        {
            first_idx = middle_idx + 1;
        }
        // Jump to left half, if the target is lesser than the middle element
        else if (target < arr[middle_idx])
        {
            last_idx = middle_idx - 1;
        }
    }
    
    return found_idx;
}

int main() {
    uint8_t arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    uint32_t target = 6;
    uint32_t index = binary_search(arr, sizeof(arr), target);
    printf("%d is found at index %d in array of size %ld\n", target, index, sizeof(arr));
    return 0;
}
