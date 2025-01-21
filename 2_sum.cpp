#include <bits/stdc++.h>

using namespace std;

/* --------------------------------Variation i - Return indices -------------------------------- */

/*
    Time - O(n^2)
    Space - O(1)
*/
vector<int> solve_1(vector<int> &nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

/*
    Hash Map
    -> Insert element with index in hash map
    -> Search for target - el in hash map

    Time - O(n)
    Space - O(n)
 */
vector<int> solve_2(vector<int> &nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(target - nums[i]) != m.end()) {
            return {m[target - nums[i]], i};
        }
        m[nums[i]] = i;
    }

    return {-1, -1};
}

/* --------------------------------Variation ii - Return true/false -------------------------------- */

/*
    Hash Map

    Time - O(n)
    Space - O(n)
*/
bool solve_3(vector<int> &nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(target - nums[i]) != m.end()) {
            return true;
        }
        m[nums[i]] = i;
    }

    return false;
}

/*
    Two pointer

    Time - O(nlogn)
    Space - O(1)
*/
bool solve_4(vector<int> &nums, int target) {
    int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];

        if (sum == target) {
            return true;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto p = solve_1(nums, target);

    cout << p[0] << " " << p[1] << '\n';

    return 0;
}