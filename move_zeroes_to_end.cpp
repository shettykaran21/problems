#include <bits/stdc++.h>

using namespace std;

/*
    Time - O(n) + O(n)
    Space - O(n)
*/
void solve_1(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;
    for (int& el : nums) {
        if (el != 0) {
            temp.push_back(el);
        }
    }

    for (int i = temp.size(); i < n; ++i) {
        temp.push_back(0);
    }

    // Copy all elements back to original array
    for (int i = 0; i < n; ++i) {
        nums[i] = temp[i];
    }
}

/*
    Optimal
    -> Point j at first 0
    -> Iterate and swap if nums[i] != 0 with nums[j]

    Time - O(n)
    Space - O(1)
*/
void solve_2(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return;

    int j = 0;
    // Point j at first 0
    for (int& el : nums) {
        if (el == 0) {
            break;
        }
        j++;
    }

    for (int i = j + 1; i < n; ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    return 0;
}