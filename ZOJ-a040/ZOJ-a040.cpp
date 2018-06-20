#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Determine whether the number is Armstrong's number */
bool isArmstrong(int num) {
    string temp = to_string(num);
    int armstrong = 0;
    for (int i = 0; i < temp.length(); ++i)
        armstrong += (pow(temp[i] - '0', temp.length()));
    
    if (armstrong == num)
        return true;
    return false;
}

int main(void) {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        // Print the result
        int count = 0;
        for (int i = n; i <= m; ++i) {
            if (isArmstrong(i)) {
                printf("%d ", i);
                ++count;
            }
        }
        
        if (count == 0)
            printf("none\n");
        else
            printf("\n");
    }

    return 0;
}