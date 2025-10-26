#include <bits/stdc++.h>

using namespace std;

/*
    Euclidean algorithm - gcd(a, b) = gcd(a - b, b)
    Do this subtraction until one of the numbers is 0. Then, the other number is the GCD.
    (No need to check the proff of this algorithm, we are here to code, not do maths 😉)

    Optimization is instead of repeatedly subtracting a - b, just use modulo operator.
    Eg. If a = 100, b = 5, if we subtract, 100 - 5 = 95, 95 - 5 = 90, 90 - 5 = 85..... this will go on..
    Instead, we can do 100 % 5 = 0, we directly have one of the numbers as 0, and hence the answer is the other number i.e. 5
*/

int gcd(int a, int b) {
    return gcd(b, a % b);
}

int main() {
    return 0;
}