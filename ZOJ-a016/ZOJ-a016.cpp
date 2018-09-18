#include <cstdio>
#include <iostream>
#include <set>

#define MAX 9

using namespace std;

set<int> row[9], col[9], block[3][3];

// Add each number into set
void addIntoSet(int i, int j, int num) {
    row[i].insert(num);
    col[j].insert(num);
    block[i / 3][j / 3].insert(num);
}

int main(void) {
    int firstLine[MAX] = { 0 };

    while (scanf("%d %d %d %d %d %d %d %d %d",
        &firstLine[0], &firstLine[1], &firstLine[2],
        &firstLine[3], &firstLine[4], &firstLine[5],
        &firstLine[6], &firstLine[7], &firstLine[8]) != EOF) {
        // Initial set
        for (int i = 0; i < MAX; ++i) {
            row[i].clear();
            col[i].clear();
            block[i / 3][i % 3].clear();
        }
      
        // Input a Sudoku
        for (int i = 0; i < MAX; ++i) {
            if (firstLine[i] > 0 && firstLine[i] < 10)
                addIntoSet(0, i, firstLine[i]);
        }
        
        int tmp;
        for (int i = 1; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                scanf("%d", &tmp);
                if (tmp > 0 && tmp < 10)
                    addIntoSet(i, j, tmp);
            }
        }

        // Check the input is Sudoku
        bool isSudoku = true;
        for (int i = 0; i < MAX; ++i) {
            if (row[i].size() != MAX || col[i].size() != MAX || block[i / 3][i % 3].size() != MAX) {
                isSudoku = false;
                break;
            }
        }

        // Print the result
        if (isSudoku)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}