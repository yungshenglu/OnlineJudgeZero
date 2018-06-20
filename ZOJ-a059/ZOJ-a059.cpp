#include <cstdio>
#include <cmath>
#include <iostream>

#define MAX 105

using namespace std;

int main(void) {
    int T;

    while (scanf("%d", &T) != EOF) {
        int a, b, sum[MAX] = { 0 };
        for (int t = 0; t < T; ++t) {
            scanf("%d %d", &a, &b);
            for (int i = a; i <= b; ++i) {
                if (pow((int)(sqrt(i)), 2) == i)
                    sum[t] += i;
            }
        }

        // Print the result
        for (int t = 0; t < T; ++t)
            printf("Case %d: %d\n", t + 1, sum[t]);
    }

    return 0;
}