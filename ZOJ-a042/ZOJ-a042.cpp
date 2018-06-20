#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF) {
        // Print the result
        printf("%d\n", ((n - 1) * n) + 2);
    }

    return 0;
}