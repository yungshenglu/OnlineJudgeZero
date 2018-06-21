#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < n; ++i) {
            if (i % 7)
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}