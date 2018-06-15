#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    string num;

    while (cin >> num) {
        int start = 0, end = num.length() - 1;

        // Remove the continuous zero at the first
        while (num[start] == '0')
            ++start;
        
        // Remove the continuous zero at the end
        while (num[end] == '0')
            --end;

        // When all the input are zeros and print the result
        if (start > end)
            printf("0\n");
        else {
            for (int i = end; i >= start; --i)
                printf("%c", num[i]);
            printf("\n");
        }
    }

    return 0;
}