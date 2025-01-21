#include <bits/stdc++.h>

using namespace std;

/*
    Sort

    Time - O(nlogn)
    Space - O(1)
*/
void solve_1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
}

/*
    Frequency
    -> Count no. of 0s, 1s, 2s and replace it in original array

    Time - O(n) + O(n)
    Space - O(1)
*/
void solve_2(vector<int> &nums) {
    int count_0 = 0, count_1 = 0, count_2 = 0;

    for (int &el : nums) {
        if (el == 0) {
            count_0++;
        } else if (el == 1) {
            count_1++;
        } else {
            count_2++;
        }
    }

    // Replace the places in the original array:
    for (int i = 0; i < count_0; i++) nums[i] = 0;
    for (int i = count_0; i < count_0 + count_1; i++) nums[i] = 1;
    for (int i = count_0 + count_1; i < nums.size(); i++) nums[i] = 2;
}

/*
    Dutch National Flag Algorithm (Three Pointers)

    Rules
    1. [0 ... low - 1] contains 0. [Extreme left part]
    2. [low .. mid - 1] contains 1.
    3. [high + 1 ... n - 1] contains 2. [Extreme right part]
    The middle part i.e. [mid ... high] is the unsorted segment.

    Remember these 3 rules and accordingly move the pointers 😌

    Time - O(n) - In every iteration, the unsorted section is shrinking by 1
    Space - O(1)
*/
void solve_3(vector<int> &nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    solve_3(nums);

    for (int &el : nums) {
        cout << el << " ";
    }
    cout << '\n';

    return 0;
}