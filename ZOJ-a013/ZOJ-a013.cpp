#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <map>

#define MAX 7

using namespace std;

const string roman = "MDCLXVI";
const int number[MAX] = { 1000, 500, 100, 50, 10, 5, 1 };

// Transfer roman to integer number
int roman2number(string str) {
    int result = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (roman.find(str[i]) < roman.find(str[i - 1]) && i != 0)
            result -= number[roman.find(str[i - 1])] * 2;
        result += number[roman.find(str[i])];
    }

    return result;
}

// Transfer integer number to roman
string number2roman(int num) {
    string result = "";
    int tmp, key;
    for (int i = MAX - 1; i >= 0; i -= 2) {
        tmp = num % 10;
        num /= 10;
        key = 0;

        if (tmp == 4) {
            result.insert(0, roman, i - 1, 1);
            result.insert(0, roman, i, 1);
        }
        else if (tmp == 9) {
            result.insert(0, roman, i - 2, 1);
            result.insert(0, roman, i, 1);
        }
        else {
            tmp *= pow(10, ((MAX - 1) - i) / 2);
            while (i > 0 && tmp >= number[i - 1]) {
                tmp -= number[i - 1];
                key = 1;
            }
            while (tmp >= number[i]) {
                tmp -= number[i];
                result.insert(0, roman, i, 1);
            }
            if (i > 0 && key == 1)
                result.insert(0, roman, i - 1, 1);
        }
    }

    return result;
}

int main(void) {
    string str1, str2;

    while (cin >> str1) {
        // End of input
        if (str1 == "#")
            break;
        
        cin >> str2;

        // Output the result
        if (str1 == str2)
            cout << "ZERO" << endl;
        else {
            int num1 = roman2number(str1), num2 = roman2number(str2);
            int result = (num1 > num2) ? num1 - num2 : num2 - num1;
            cout << number2roman(result) << endl;
        }
    }

    return 0;
}