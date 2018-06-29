#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int T;

    while (scanf("%d", &T) != EOF)  {
        string num;
        for (int t = 0; t < T; ++t) {
            cin >> num;

            long long int result = num[0] - '0';
            for (int i = 1; i < num.length(); ++i)
                result *= (num[i] - '0');

            // Print the result
            printf("%lld\n", result);
        }
    }

    return 0;
}