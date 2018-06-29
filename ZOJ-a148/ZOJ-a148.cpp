#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    long long int n;

    while (scanf("%lld", &n) != EOF)  {
        long long int score, avg = 0;
        for (long long int i = 0; i < n; ++i) {
            scanf("%lld", &score);
            avg += score;
        }

        // Print the result
        if (avg <= 59 * n)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}