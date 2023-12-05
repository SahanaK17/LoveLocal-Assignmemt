#include <stdio.h>
#include <stdlib.h>

int* majorityElements(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int candidate1 = 0, count1 = 0;
    int candidate2 = 0, count2 = 0;

    // Voting Phase
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Counting Phase
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Check if candidates are majority elements
    int threshold = numsSize / 3;
    *returnSize = 0;
    int* result = (int*)malloc(2 * sizeof(int));

    if (count1 > threshold) {
        result[(*returnSize)++] = candidate1;
    }
    if (count2 > threshold) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    int numsSize;

    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = majorityElements(nums, numsSize, &returnSize);

    printf("Majority Elements: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(nums);
    free(result);

    return 0;
}
