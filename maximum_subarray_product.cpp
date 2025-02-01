#include <bits/stdc++.h>

using namespace std;

/*
    Optimal - Kadane's Algorithm

    Case 1. All +ve
    Case 2. Even -ve
    Case 3. Odd -ve
        If we remove one -ve number, we will have even no. of -ve nos. remaining
        So, after removing one -ve, max product will either be in the prefix product or suffix product

    Edge case: When product is 0, reinitialize it to 1
*/
int solve(vector<int> &nums) {
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (prefix == 0) prefix = 1;
        if (suffix = 0) suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
}

int main() {
    return 0;
}