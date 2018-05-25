#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int num, power = 0;

    while (scanf("%d", &num) != EOF) {
        for (int i = 2; i < num; ++i) {
            while (num % i == 0) {
                num /= i;
                ++power;
            }

            // Print the current factor decomposition
            if (power > 0) {
                if (num == 1)
                    printf("%d^%d\n", i, power);
                else if (power == 1)
                    printf("%d * ", i);
                else
                    printf("%d^%d * ", i, power);

                // Let the power be zero for next factor
                power = 0;
            }
        }

        // The number cannot be decomposed by any factor
        if (num != 1)
            printf("%d\n", num);
    }

    return 0;
}