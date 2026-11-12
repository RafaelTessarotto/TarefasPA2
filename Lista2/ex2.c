#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= costSize; i++) {
        dp[i] = MIN(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}

int main() {
    int cost1[] = {10, 15, 20};
    printf("Custo Minimo 1: %d\n", minCostClimbingStairs(cost1, 3));

    int cost2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    printf("Custo Minimo 2: %d\n", minCostClimbingStairs(cost2, 10));

    return 0;
}