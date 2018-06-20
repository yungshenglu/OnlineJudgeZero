#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF) {
        // Print the result
        printf("%d\n", (2 + (n - 1) * n));
    }

    return 0;
}