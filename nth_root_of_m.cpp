#include <bits/stdc++.h>

using namespace std;

/*
    Time - O(log2m) * log2n
        - The log2n to calculate pow()
    Space - O(1)
*/
int solve_1(int n, int m) {
    int low = 1, high = m / n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long x = pow(mid, n);

        if (x == m) {
            return mid;
        } else if (x < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    return 0;
}