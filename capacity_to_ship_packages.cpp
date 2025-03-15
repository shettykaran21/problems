#include <bits/stdc++.h>

using namespace std;

bool isCurrentCapacityPossible(vector<int> &weights, int days, int maxCapacity) {
    long long currentTotalLoad = 0;
    int noOfDays = 0;

    for (int weight : weights) {
        if (currentTotalLoad + weight > maxCapacity) {
            noOfDays++;
            currentTotalLoad = weight;
        } else {
            currentTotalLoad += weight;
        }
    }
    noOfDays++;

    return noOfDays <= days;
}

/*
    Time - O(logn) * O(n)
    Space - O(1)
*/
int solve(vector<int> &weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isCurrentCapacityPossible(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solve(weights, 4) << '\n';

    return 0;
}