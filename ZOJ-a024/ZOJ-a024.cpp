#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF) {
        if (a < b)
            swap(a, b);
        
        int r = 0;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        
        // Print the result
        printf("%d\n", a);
    }

    return 0;
}