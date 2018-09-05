#include <cstdio>
#include <iostream>
#include <string>

#define MAX 7

using namespace std;

int main(void) {
    string word;
    while (cin >> word) {
        int password[6] = { 0 };
        for (int i = 0; i < MAX - 1; ++i)
            printf("%d", (word[i + 1] >= word[i]) ? word[i + 1] - word[i] : word[i] - word[i + 1]);
        puts("");
    }

    return 0;
}