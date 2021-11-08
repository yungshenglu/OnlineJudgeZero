#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int plus_carry = 0, multiply_carry = 0;

// Add operation
string addOp(string num1, string num2) {
    int length1 = num1.length(), length2 = num2.length();

    // Append zero before the smaller size number
    if (length1 > length2) {
        for (int i = 0; i < (length1 - length2); ++i)
            num2 = '0' + num2;
    }
    else if (length2 > length1) {
        for (int i = 0; i < (length2 - length1); ++i)
            num1 = '0' + num1;
    }
    length1 = num1.length();
    length2 = num2.length();

    char ch;
    string result = "";
    for (int i = length1 - 1; i >= 0; --i) {
        int n = (num1[i] - '0') + (num2[i] - '0') + plus_carry;
        if (n > 9) {
            ch = (n % 10) + '0';
            plus_carry = n / 10;
        }
        else {
            ch = n + '0';
            plus_carry = 0;
        }
        result = ch + result;
    }

    if (plus_carry) {
        ch = plus_carry + '0';
        result = ch + result;
        plus_carry = 0;
    }

    return result;
}

// Minus operation
string minusOp(string num1, string num2) {
    int length1 = num1.length(), length2 = num2.length();

    // Determine whether the two number are identical
    if (num1 == num2)
        return "0";

    bool isNegative = false;
    if (length1 > length2) {
        // Append zero in front of the smaller number
        for (int i = 0; i < (length1 - length2); ++i)
            num2 = '0' + num2;
    }
    else {
        // Determine the result would be negative and swap if negative
        if (length1 < length2) {
            // Append zero in front of the smaller number
            for (int i = 0; i < (length2 - length1); ++i)
                num1 = '0' + num1;
            isNegative = true;
            num1.swap(num2);
        }
        else if (length1 == length2) {
            for (int i = 0; i < length1; ++i) {
                if (num1[i] > num2[i])
                    break;
                else if (num1[i] == num2[i])
                    continue;
                else {
                    isNegative = true;
                    num1.swap(num2);
                }
            }
        }
    }
    length1 = num1.length();
    length2 = num2.length();

    string result = "";
    for (int i = length1 - 1; i >= 0; --i) {
        int n = (num1[i] - '0') - (num2[i] - '0') - plus_carry;
        char ch;
        if (n >= 0) {
            ch = n + '0';
            plus_carry = 0;
        }
        else {
            ch = (10 + n) + '0';
            plus_carry = 1;
        }
        result = ch + result;
    }

    // Erase zero in front of the result
    if (result[0] == '0') {
        for (int i = 1; i < result.length(); ++i) {
            if (result[i] != '0') {
                result.erase(0, i);
                break;
            }
        }
    }

    // Add negative sign before the result
    result = (isNegative) ? '-' + result : result;
    return result;
}

// Multiply operation
string multiplyOp(string num1, string num2) {
    int length1 = num1.length(), length2 = num2.length();

    bool isZero = true;
    string result = "0";
    for (int j = length2 - 1; j >= 0; --j) {
        char ch;
        string temp_result = "", curr_result = "";
        for (int i = length1 - 1; i >= 0; --i) {
            int n = ((num2[j] - '0') * (num1[i] - '0')) + multiply_carry;
            isZero = (n) ? false : true;
            if (n > 9) {
                ch = (n % 10) + '0';
                multiply_carry = n / 10;
            }
            else {
                ch = n + '0';
                multiply_carry = 0;
            }
            temp_result = ch + temp_result;
        }

        // Add the carry
        if (multiply_carry) {
            ch = multiply_carry + '0';
            temp_result = ch + temp_result;
        }
        
        // Add each result of multiply
        for (int k = 0; k < (length2 - 1 - j); ++k)
            temp_result = temp_result + '0';
        temp_result = (isZero) ? "0" : temp_result;

        curr_result = addOp(temp_result, result);
        result = curr_result;
    }

    return result;
}

// Divide operation
string divideOp(string num1, string num2) {
    int length1 = num1.length(), length2 = num2.length();

    if (num1 == "0" || num2 == "0")
        return "0";
    else if (num2 == "1")
        return num1;
    else if (num1 == num2)
        return "1";
    else {
        // Determine whether num1 is greater than num2
        if (length1 < length2)
            return "0";
        else if (length1 == length2) {
            for (int i = 0; i < length1; ++i) {
                if (num1[i] < num2[i])
                    return "0";
            }
        }
    }

 
    string result = "", temp_result = "";
    int size = length2;
    for (int i = 0; i < length1; i += size) {
        cout << temp_result << endl;
        // Determine the result in the last round can be divided
        if (temp_result == "0") {
            temp_result = "";
            result = (size > 1) ? result + '0' : result;
        }

        // Append number into divided number
        string divided = temp_result + num1.substr(i, size - temp_result.length());
        while (divided[0] == '0' && num2.length() > 1) {
            divided.erase(0);
            result = result + '0';
            continue;
        }

        // Determine whether to append one more digit
        string minus_result = minusOp(divided, num2);
        if (minus_result[0] == '-') {
            divided = divided + num1[i + size + 1];
            ++i;
        }

        cout << divided << " - " << num2 << " = " << result << endl;
 
        int n = 0;
        do {
            temp_result = divided;
            divided = minusOp(divided, num2);
            ++n;
        } while (divided[0] != '-');

        // Add current result into final result
        char ch = (n - 1) + '0';
        result = result + ch;
    }

    return result;
}

int main(void) {
    string num1, num2, op;

    while (cin >> num1 >> op >> num2) {
        plus_carry = multiply_carry = 0;
        if (op == "+")
            cout << addOp(num1, num2) << endl;
        else if (op == "-")
            cout << minusOp(num1, num2) << endl;
        else if (op == "*")
            cout << multiplyOp(num1, num2) << endl;
        else if (op == "/")
            cout << divideOp(num1, num2) << endl;
    }

    return 0;
} 