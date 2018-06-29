#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int m, n;

    while (scanf("%d %d", &n, &m) != EOF)  {
        int i = 0, sum = 0;
        do {
            sum += n;
            ++n;
            ++i;
        } while (sum <= m);
        
        // Print the result
        printf("%d\n", i);
        
    }

    return 0;
}