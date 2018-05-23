#include <cstdio>
#include <iostream>

#define MAX 5

using namespace std;

int main(void) {
    int T, arr[MAX] = { 0 };

    while (scanf("%d", &T) != EOF) {
        for (int t = 0; t < T; ++t) {
            for (int i = 0; i < MAX - 1; ++i)
                scanf("%d", &arr[i]);
            
            // Determine the series
            if (arr[1] - arr[0] == arr[2] - arr[1])
                arr[4] = arr[3] + (arr[1] - arr[0]);
            else if (arr[1] / arr[0] == arr[2] / arr[1])
                arr[4] = arr[3] * (arr[1] / arr[0]);
            
            // Print the result
            for (int i = 0; i < MAX; ++i)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }

    return 0;
}