#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int M, N;

    while (scanf("%d %d", &M, &N) != EOF) {
        if (M == N)
            printf("%d\n", N);
        else
            printf("%d\n", N + 1);
    }

    return 0;
}