#include <bits/stdc++.h>

using namespace std;

/*
    Time - O(n^2)
    Space - O(1)
*/
int solve_1(vector<int> &nums) {
    int n = nums.size(), maxi = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = i; j < n; ++j) {
            sum += nums[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

/*
    Kadane's algorithm
    Negative sum will decrease the overall value, so reinitialize the sum to 0 when negative
    Time - O(n)
    Space - O(1)
*/
int solve_2(vector<int> &nums) {
    int n = nums.size();
    long long maxi = LONG_MIN, sum = 0;

    for (int &el : nums) {
        sum += el;
        maxi = max(maxi, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return sum;
}

int main() {
    return 0;
}