#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProf = 0;

    for (int i = 1; i < pricesSize; i++) {
        minPrice = MIN(minPrice, prices[i]);
        maxProf = MAX(maxProf, prices[i] - minPrice);
    }
    return maxProf;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    printf("Lucro Maximo 1: %d\n", maxProfit(prices1, 6));

    int prices2[] = {7, 6, 4, 3, 1};
    printf("Lucro Maximo 2: %d\n", maxProfit(prices2, 5));

    return 0;
}