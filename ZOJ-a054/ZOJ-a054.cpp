#include <cstdio>
#include <iostream>
#include <string>
#include <map>

#define REGION 26
#define MAX 9

using namespace std;

int main(void) {
    // Build a table to store all code number for each region
    map< char, int > region;
    for (int i = 0; i < REGION; ++i) {
        if (i == 8)
            region['A' + i] = 34;
        else if (i > 8 && i < 14)
            region['A' + i] = 9 + i;
        else if (i == 14)
            region['A' + i] = 35;
        else if ((i > 14 && i < 22) || i == REGION - 1)
            region['A' + i] = 8 + i;
        else if (i > 22 && i < REGION - 1)
            region['A' + i] = 7 + i;
        else
            region['A' + i] = 10 + i;
    }

    string ID;
    while (cin >> ID) {
        // Add the following number in ID by multiply the weight
        int checksum = 0;
        for (int i = 0; i < MAX - 1; ++i)
            checksum += ((ID[i] - '0') * (8 - i));
        checksum += (ID[8] - '0');

        string letters = "";
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            int code = (region[ch] % 10) * 9 + (region[ch] / 10);
            if ((checksum + code) % 10 == 0)
                letters += ch;
        }
        
        // Print the result
        cout << letters << endl;
    }

    return 0;
}