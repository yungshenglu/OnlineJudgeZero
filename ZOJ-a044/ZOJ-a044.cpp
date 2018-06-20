#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF) {
        // Print the result
        printf("%d\n", n * (n * n + 5) / 6 + 1);
    }

    return 0;
}