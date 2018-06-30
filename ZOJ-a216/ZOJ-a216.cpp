#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    long long int n;

    while (scanf("%lld", &n) != EOF)  {
        long long int fn = 1, gn = 1;
        for (long long int i = 2; i <= n; ++i) {
            fn += i;
            gn += fn;
        }
        
        // Print the result
        printf("%lld %lld\n", fn, gn);
    }

    return 0;
}