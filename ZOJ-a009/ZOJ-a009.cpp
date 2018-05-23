#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;

    while (getline(cin, str)) {
        // Decoding and print the result
        for (int i = 0; i < str.size(); ++i)
            printf("%c", (char)(str[i] - 7));
        printf("\n");
    }

    return 0;
}