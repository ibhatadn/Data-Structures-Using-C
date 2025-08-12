
#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define N 4

int reduceMatrix(int cost[N][N], int row[N], int col[N]) {
    int reduction = 0;

    for (int i = 0; i < N; i++) {
        row[i] = INF;
        for (int j = 0; j < N; j++)
            if (cost[i][j] < row[i])
                row[i] = cost[i][j];
        for (int j = 0; j < N; j++)
            cost[i][j] -= row[i];
    }

    for (int j = 0; j < N; j++) {
        col[j] = INF;
        for (int i = 0; i < N; i++)
            if (cost[i][j] < col[j])
                col[j] = cost[i][j];
        for (int i = 0; i < N; i++)
            cost[i][j] -= col[j];
    }

    for (int i = 0; i < N; i++) reduction += row[i];
    for (int j = 0; j < N; j++) reduction += col[j];
    return reduction;
}

int main() {
    int cost[N][N] = {
        {INF, 10, 15, 20},
        {10, INF, 35, 25},
        {15, 35, INF, 30},
        {20, 25, 30, INF}
    };

    int row[N], col[N];
    int reduction = reduceMatrix(cost, row, col);
    printf("Cost after reduction (lower bound): %d\n", reduction);
    return 0;
}
