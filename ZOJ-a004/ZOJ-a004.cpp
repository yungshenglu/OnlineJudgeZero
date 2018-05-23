#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    int year;

    while (scanf("%d", &year) != EOF) {
        // Determine whether the year is leap or not
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            printf("閏年\n");
        else
            printf("平年\n");
    }

    return 0;
}