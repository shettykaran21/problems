#include <bits/stdc++.h>

using namespace std;

/*
    lcm(a, b) = (a * b) / gcd(a, b)

    Time complexity - O(log(min(a, b)))
    Space complexity - O(1)
*/

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cout << lcm(7, 2) << '\n';
    return 0;
}