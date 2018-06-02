#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 4

using namespace std;

int main(void) {
    int T, side[MAX] = { 0 };

    while (scanf("%d", &T) != EOF) {
        for (int t = 0; t < T; ++t) {
            // Read the input length of each side and sum of them
            int sum = 0;
            for (int i = 0; i < MAX; ++i) {
                scanf("%d", &side[i]);
                sum += side[i];
            }

            bool isBanana = false;
            for (int i = 0; i < MAX; ++i) {
                if (side[i] >= (sum - side[i]))
                    isBanana = true;
            }
            
            // Sort all sides' length in increasing order
            sort(side, side + MAX);

            // Determine the which quadrangle it is
            if (side[0] == side[1] && side[2] == side[3]) {
                if (side[1] == side[2])
                    printf("square\n");
                else
                    printf("rectangle\n");
            }
            else if (!isBanana)
                printf("quadrangle\n");
            else 
                printf("banana\n");
        }
    }

    return 0;
}