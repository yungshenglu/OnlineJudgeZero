#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF) {
        // Print the result
        printf("%d\n", a + b);
    }

    return 0;
}