#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int N;

    while (scanf("%d", &N) != EOF) {
        while (N > 0) {
            // Reverse the input number
            printf("%d", N % 10);
            N /= 10;
        }
        printf("\n");
    }

    return 0;
}