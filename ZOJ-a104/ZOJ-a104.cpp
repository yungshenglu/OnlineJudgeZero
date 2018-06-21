#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, num;

    while (scanf("%d", &n) != EOF) {
        vector<int> list;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            list.push_back(num);
        }

        // Sorting
        sort(list.begin(), list.end());

        // Print the result
        for (int i = 0; i < n - 1; ++i)
            printf("%d ", list[i]);
        printf("%d\n", list[n - 1]);
    }

    return 0;
}