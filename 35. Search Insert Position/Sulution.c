#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {  // Faster than 100% solutions!!!
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            break;
        }
    }
    
    return i;
}