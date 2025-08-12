
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 99999

struct Node {
    int level;
    int profit;
    int weight;
};

int queue_front = 0, queue_rear = 0;
struct Node queue[MAX];

void enqueue(struct Node n) {
    queue[queue_rear++] = n;
}

struct Node dequeue() {
    return queue[queue_front++];
}

int knapsack(int weights[], int profits[], int n, int capacity) {
    struct Node u, v;
    int maxProfit = 0;

    v.level = -1;
    v.profit = v.weight = 0;
    enqueue(v);

    while (queue_front < queue_rear) {
        v = dequeue();
        if (v.level == n - 1)
            continue;

        u.level = v.level + 1;

        u.weight = v.weight + weights[u.level];
        u.profit = v.profit + profits[u.level];

        if (u.weight <= capacity && u.profit > maxProfit)
            maxProfit = u.profit;

        if (u.weight <= capacity)
            enqueue(u);

        u.weight = v.weight;
        u.profit = v.profit;
        enqueue(u);
    }

    return maxProfit;
}

int main() {
    int weights[] = {1, 2, 3};
    int profits[] = {60, 100, 120};
    int capacity = 5;
    int n = 3;

    printf("Max Profit = %d\n", knapsack(weights, profits, n, capacity));
    return 0;
}
