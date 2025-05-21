#include <stdio.h>
#include <stdint.h>

uint32_t binary_search(uint8_t arr[], uint32_t size, uint32_t target)
{
    // Pre-requisite: Binary search requires array to be sorted in ascending order.
    uint32_t left_idx = 0;
    uint32_t right_idx = size - 1;
    uint32_t found_idx = 0;
    
    // Repeat until the left and right pointers meet each other
    while(left_idx <= right_idx)
    {
        // Divide the array into two halves
        uint32_t number_of_elements = right_idx - left_idx;
        uint32_t middle_idx = left_idx + (number_of_elements / 2);
        printf("left: %d, mid = %d, right: %d\n", left_idx, middle_idx, right_idx);

        // Return if the target is found at the middle index
        if (arr[middle_idx] == target)
        {
            found_idx = middle_idx;
            break;
        }
        // Jump to right half, if the target is greater than the middle element
        if (target > arr[middle_idx])
        {
            left_idx = middle_idx + 1;
        }
        // Jump to left half, if the target is lesser than the middle element
        else
        {
            right_idx = middle_idx - 1;
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
