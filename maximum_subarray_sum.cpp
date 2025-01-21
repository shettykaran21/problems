#include <bits/stdc++.h>

using namespace std;

/* --------------------------------Variation i - Return maximum sum -------------------------------- */

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

/* --------------------------------Variation ii - Print the Subarray with Maximum Sum -------------------------------- */

/*
    Whenever sum is 0, it means a new subarray is starting
    Time - O(n)
    Space - O(1)
*/
pair<int, int> solve_3(vector<int> &nums) {
    int n = nums.size();
    long long maxi = LONG_MIN, sum = 0;

    int start = 0, startIndex = 0, endIndex = 0;

    for (int i = 0; i < n; ++i) {
        if (sum == 0) {
            start = i;
        }

        sum += nums[i];

        if (sum > maxi) {
            startIndex = start, endIndex = i;
            maxi = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    return make_pair(startIndex, endIndex);
}

int main() {
    return 0;
}