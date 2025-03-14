#include <bits/stdc++.h>

using namespace std;

int solve_1(vector<int> &piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hourCount = 0;
        for (int pile : piles) {
            hourCount += ceil((double)pile / mid);
        }

        if (hourCount <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}