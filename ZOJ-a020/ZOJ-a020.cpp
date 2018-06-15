#include <cstdio>
#include <iostream>
#include <string>
#include <map>

#define REGION 26
#define MAX 10

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
    bool isReal = false;
    while (cin >> ID) {
        // Check the length of ID
        if (ID.length() > 10) {
            printf("fake\n");
            continue;
        }
        else {
            // Map to the code number in region and compute
            int checksum = (region[ID[0]] / 10) + (region[ID[0]] % 10) * 9;

            // Add the following number in ID by multiply the weight
            for (int i = 1; i < MAX - 1; ++i)
                checksum += ((ID[i] - '0') * (9 - i));
            checksum += (ID[9] - '0');

            // Check whether the ID is real or fake
            isReal = (checksum % 10) ? false : true;
        }

        // Print the result
        if (isReal)
            printf("real\n");
        else
            printf("fake\n");
    }

    return 0;
}
