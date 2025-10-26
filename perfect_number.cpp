#include <bits/stdc++.h>

using namespace std;

/*
    Perfect number is a number whose sum of divisor is equal to the actual number.
*/

/*
    Time - O(sqrt(n))
    Space - O(1)
*/
bool isPerfect(int n) {
    if (n == 1) return false;

    long long sum = 0;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;

            int other_divisor = n / i;
            if (i != 1 && i != other_divisor) {
                sum += other_divisor;
            }
        }
    }

    return sum == n;
};

int main() {
    cout << isPerfect(36) << '\n';

    return 0;
}