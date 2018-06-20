#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

#define MAX 1010

using namespace std;

int main(void) {
    string str;

    while (cin >> str) {
        stack<char> palindromes;
        if (str.length() > 1) {
            // Only need to push half length of string
            int ptr = 0;
            for (; ptr < str.length() / 2; ++ptr)
                palindromes.push(str[ptr]);
            
            // If the length of string is odd, then pass the middle character
            ptr = (str.length() % 2) ? (++ptr) : ptr;

            // Pop out the stack to check whether the string is palindromes
            while ((ptr < str.length()) && (palindromes.top() == str[ptr])) {
                palindromes.pop();
                ++ptr;
            }
        }

        // Check whether the string is palindromes
        if (palindromes.empty())
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}