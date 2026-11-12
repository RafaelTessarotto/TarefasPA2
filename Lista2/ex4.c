#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[numsSize - 1];
}

int main() {
    int nums1[] = {1, 2, 3, 1};
    printf("Maximo Roubado 1: %d\n", rob(nums1, 4));

    int nums2[] = {2, 7, 9, 3, 1};
    printf("Maximo Roubado 2: %d\n", rob(nums2, 5));

    return 0;
}