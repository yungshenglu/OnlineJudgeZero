#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N;

    while (scanf("%d", &N) != EOF) {
        string binary;

        // Convert the input number into binary
        while (N > 0) {
            binary = ((N % 2) ? '1' : '0') + binary;
            N /= 2;
        }

        // Print the result
        cout << binary << endl;
    }

    return 0;
}