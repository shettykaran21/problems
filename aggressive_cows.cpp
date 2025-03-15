#include <bits/stdc++.h>

using namespace std;

bool isCurrentDistancePossible(vector<int> &stalls, int cows, int currentDistanceBetweenCows) {
    int lastPlaced = stalls[0];
    int noOfCowsPlaced = 1;

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPlaced >= currentDistanceBetweenCows) {
            lastPlaced = stalls[i];
            noOfCowsPlaced++;
        }

        if (noOfCowsPlaced == cows) {
            return true;
        }
    }

    return false;
}

/*
    Time - O(n*logn)
    Space - O(1)
*/
int solve(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls.back() - stalls[0];
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isCurrentDistancePossible(stalls, cows, mid)) {
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