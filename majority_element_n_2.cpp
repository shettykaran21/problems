#include <bits/stdc++.h>

using namespace std;

/*
    Brute force
    Time - O(n^2)
    Space - O(1)
*/
int solve_1(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int count = 1;

        for (int j = i + 1; j < n; ++j) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        if (count > n / 2) {
            return nums[i];
        }
    }

    return -1;
}

/*
    Better - Hash Map

    Time - O(n) + O(n)
    Space - O(n)
*/
int solve_2(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> m;

    for (int &el : nums) {
        m[el]++;
    }

    for (auto &i : m) {
        if (i.second > n / 2) {
            return i.first;
        }
    }

    return -1;
}

/*
    Optimal - Moore's Voting Algorithm
*/
int solve_3(vector<int> &nums) {
    int count = 0;
    int candidate;

    for (int &el : nums) {
        if (count == 0) {
            candidate = el;
            count++;
        } else if (el == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    return 0;
}