#include <bits/stdc++.h>

using namespace std;

/*
    Time - O(logn)
    Space - O(1)
*/
int solve_1(int n) {
    int low = 1, high = n / 2;
    int ans;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}