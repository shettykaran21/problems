#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.end(), nums.end());
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int count = 0;
        for (int num : nums) {
            count += ceil((double)num / mid);
        }

        if (count <= threshold) {
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