#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &bloomDay, int candidate, int m, int k) {
    int count = 0, noOfBouquets = 0;

    for (int el : bloomDay) {
        if (el <= candidate) {
            count++;
        } else {
            noOfBouquets += count / k;
            count = 0;
        }
    }
    noOfBouquets += count / k;

    return noOfBouquets >= m;
}

/*
    Time - log2n * n
    Space - O(1)
*/
int solve(vector<int> &bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(bloomDay, mid, m, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    cout << solve(bloomDay, 2, 3) << '\n';

    return 0;
}