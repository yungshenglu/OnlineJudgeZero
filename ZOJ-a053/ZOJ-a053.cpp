#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int N;

    while (scanf("%d", &N) != EOF) {
        if (N <= 10)
            printf("%d\n", N * 6);
        else if (N > 10 && N <= 20)
            printf("%d\n", 60 + (N - 10) * 2);
        else if (N > 20 && N <= 40)
            printf("%d\n", 80 + (N - 20));
        else
            printf("100\n");
    }

    return 0;
}