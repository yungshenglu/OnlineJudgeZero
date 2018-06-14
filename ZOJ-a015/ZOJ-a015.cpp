#include <cstdio>
#include <iostream>

#define MAX 100

using namespace std;

int main(void) {
    int R, C;

    while (scanf("%d %d", &R, &C) != EOF) {
        int matrix[MAX][MAX];

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j)
                scanf("%d", &matrix[i][j]);
        }

        // Print the result in transport matrix
        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < R; ++i)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}