#include <cstdio>
#include <iostream>

#define MAX 3

using namespace std;

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF) {
        int num, mod3[MAX] = { 0 };

        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            ++mod3[num % 3];
        }

        // Print the result
        for (int i = 0; i < MAX - 1; ++i)
            printf("%d ", mod3[i]);
        printf("%d\n", mod3[2]);
    }

    return 0;
}