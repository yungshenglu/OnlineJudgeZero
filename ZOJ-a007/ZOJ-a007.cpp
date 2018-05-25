#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

#define MAX 999999

using namespace std;

vector<int> prime;

/* Determine whether the number is prime or not */
bool isPrime(int num) {
	for (int i = 0; prime[i] <= sqrt(num); ++i){
		if (num % prime[i] == 0)
			return false;
	}
	return true;
}

/* Build a table to store all prime number */
void buildPrime() {
    // Initial prime table
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);

    int currPrime = prime.back();
    while (currPrime <= MAX) {
        currPrime += 2;
        if (isPrime(currPrime))
            prime.push_back(currPrime);
    }
}

int main(void) {
    int x;

    // Build prime table
    buildPrime();

    while (scanf("%d", &x) != EOF) {
        // Print the result
        if (isPrime(x))
            printf("質數\n");
        else
            printf("非質數\n");
    }

    return 0;
}