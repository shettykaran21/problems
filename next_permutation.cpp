#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Find all permutations using recursion
    -> Find next permutation from the res

    Time - ~O(n!) * O(n)
*/

/*
    In-built stl next_permutation
*/
vector<int> solve_1(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
    return nums;
}

/*
    Optimal - Implementation of in-built stl next_permutation
*/
vector<int> solve_2(vector<int> &nums) {
    int marker = -1, n = nums.size();

    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            marker = i;
            break;
        }
    }

    if (marker == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] > nums[marker]) {
            swap(nums[i], nums[marker]);
            break;
        }
    }

    reverse(nums.begin() + marker + 1, nums.end());
    return nums;
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    solve_2(nums);

    for (auto &el : nums) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}