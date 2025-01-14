#include <bits/stdc++.h>

using namespace std;

/*
    Sort the array, Check with previous value
    Time - O(nlogn)
    Space - O(1)
*/
int solve_1(vector<int> nums) {
    sort(nums.begin(), nums.end());

    int ans;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1]) {
            ans = nums[i];
            break;
        }
    }

    return ans;
}

/*
    Hash set (unordered_set)
    Insert elements in a hash set
    If element already exist, return that element, else insert in that set
    Time - O(n)
    Space - O(n)
*/
int solve_2(vector<int> &nums) {
    unordered_set<int> s;

    for (auto &el : nums) {
        if (s.find(el) != s.end()) {
            return el;
        }
        s.insert(el);
    }

    return -1;
}

/*
    Frequency array
    Time - O(n)
    Space - O(n)
*/
int solve_3(vector<int> &nums) {
    vector<int> freq(nums.size());

    for (int &el : nums) {
        if (freq[el] == 1) {
            return el;
        }
        freq[el]++;
    }

    return -1;
}

/*
    In-place frequency array
    Time - O(n)
    Space - O(1)
 */
int solve_4(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        nums[nums[i] % n] += n;
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] / n >= 2) {
            return i;
        }
    }

    return -1;
}

/*
    Floyd's Algorithm (Tortoise & Hare)
    Time - O(n)
    Space - O(1)
 */
int solve_5(vector<int> &nums) {
    int slow = 0, fast = 0;

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << solve_5(nums) << '\n';

    return 0;
}