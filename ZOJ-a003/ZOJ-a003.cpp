#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int M, D;

    while (scanf("%d %d", &M, &D) != EOF) {
        int S = (M * 2 + D) % 3;
        
        // Print the result
        switch (S) {
            case 0:
                printf("普通\n");
                break;
            case 1:
                printf("吉\n");
                break;
            case 2:
                printf("大吉\n");
                break;
        }
    }

    return 0;
}