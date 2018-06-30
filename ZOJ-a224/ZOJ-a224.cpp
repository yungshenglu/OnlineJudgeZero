#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    string str;

    while (cin >> str) {
        // Consider the lenght of input
        bool isOddLength = (str.length() % 2) ? true : false;

        // Store the input string by considering the alphabets
        map< char, int > count;
        for (int i = 0; i < str.length(); ++i) {
            // Transform the character of alphabet into lower case
            if (str[i] >= 'A' && str[i] <= 'Z')
                ++count[str[i] - 'A' + 'a'];
            else if (str[i] >= 'a' && str[i] <= 'z')
                ++count[str[i]];
        }

        // Check whether the string can be palindromes after some sorting
        int countOdd = 0;
        bool isPalindromes = true;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (count[ch] % 2) {
                // If the length of input is odd, then only one character can be count to odd
                if (isOddLength) {
                    ++countOdd;
                    if (countOdd > 1) {
                        isPalindromes = false;
                        break;
                    }
                }
                else {
                    isPalindromes = false;
                    break;
                }
            }
        }

        // Determine whether the stack is empty
        if (isPalindromes)
            printf("yes !\n");
        else
            printf("no...\n");
    }

    return 0;
}