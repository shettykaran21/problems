#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Sort
    -> Iterate and find missing number

    Time - O(nlogn) + O(n)
    Space - O(1)
*/
int solve_1(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) return i;
    }

    return n;
}

/*
    Better - Freq array

    Time - O(n) + O(n)
    Space - O(n)
*/
int solve_2(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) return i;
    }

    return n;
}

/*
    Optimal 1 -

    Time - O(n)
    Space - O(1)
*/
int solve_3(vector<int> &nums) {
    int n = nums.size();

    int expected_sum = (n * (n + 1)) / 2;
    int actual_sum = accumulate(nums.begin(), nums.end(), 0);

    return expected_sum - actual_sum;
}

/*
    Optimal 2 - XOR
    Two important properties of XOR are the following:
    1. XOR of two same numbers is always 0 i.e. a ^ a = 0.
    2. XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.

    -> xor1 = 1^2^.......^n
    -> xor2 = nums[0]^nums[1]^nums[2]^......^nums[n - 1]
    -> xor1^xor2 is the answer

    Time - O(n)
    Space - O(1)
*/
int solve_4(vector<int> &nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    /*
    for (int i = 1; i <= n; ++i) {
        xor1 = xor1 ^ i;
    }
    for (int i = 0; i < n; ++i) {
        xor2 = xor2 ^ nums[i];
    }
    */

    // We can combine the two loops into 1
    for (int i = 0; i < n; ++i) {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ nums[i];
    }

    return xor1 ^ xor2;
}

int main() {
    return 0;
}