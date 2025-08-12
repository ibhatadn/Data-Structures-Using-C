
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int bound(int weights[], int profits[], int n, int capacity) {
    int bound = 0, totalWeight = 0;

    for (int i = 0; i < n && totalWeight < capacity; i++) {
        if (totalWeight + weights[i] <= capacity) {
            bound += profits[i];
            totalWeight += weights[i];
        } else {
            int remain = capacity - totalWeight;
            bound += profits[i] * remain / weights[i];
            break;
        }
    }
    return bound;
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int profits[] = {3, 4, 5, 6};
    int capacity = 5;
    int n = 4;
    int b = bound(weights, profits, n, capacity);
    printf("Upper bound (fractional knapsack): %d\n", b);
    return 0;
}
