#include <iostream>

using namespace std;

bool sum(int* n, int* result) {
    *result += *n;
    return (--*n) && sum(n, result);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    while (cin >> n) {
        int result = 0;
        sum(&n, &result);
        cout << result << endl;
    }
    return 0;
}