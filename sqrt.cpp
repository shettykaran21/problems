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

        long long squared = (long long)mid * mid;
        if (squared == n) {
            return mid;
        } else if (squared < n) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}