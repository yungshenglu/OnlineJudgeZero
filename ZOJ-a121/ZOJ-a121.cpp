#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    else {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0)
                return false;
        }
    }

    return true;
}

int main(void) {
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF) {
        int count = 0;

        for (int i = a; i <= b; ++i) {
            if (isPrime(i))
                ++count;
        }
        count = (a == 1) ? (--count) : count;
        
        // Print the result
        printf("%d\n", count);
    }

    return 0;
}