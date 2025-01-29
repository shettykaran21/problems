#include <bits/stdc++.h>

using namespace std;

/*
    Brute force
    Time - O(n^2)
    Space - O(1)
*/
vector<int> solve_1(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;

    for (int i = 0; i < n; ++i) {
        int count = 1;

        if (res[0] != nums[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count > n / 3) {
                res.push_back(nums[i]);
            }

            if (res.size() == 2) break;
        }
    }

    return res;
}

/*
    Better - Hashing

    Time - O(n)
    Space - O(n)
*/
vector<int> solve_2(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;

    unordered_map<int, int> m;

    // Least occurance of the majority element
    int mini = n / 3 + 1;

    for (int &el : nums) {
        m[el]++;

        if (m[el] == mini) {
            res.push_back(el);
        }

        if (res.size() == 2) {
            break;
        }
    }

    return res;
}

/*
    Optimal - Moore's Voting Algorithm
*/
vector<int> solve_3(vector<int> &nums) {
    int count1 = 0, count2 = 0;
    int candidate1, candidate2;
    int n = nums.size();

    vector<int> res;

    for (int &el : nums) {
        if (count1 == 0 && el != candidate2) {
            candidate1 = el;
            count1++;
        } else if (count2 == 0 && el != candidate1) {
            candidate2 = el;
            count2++;
        } else if (el == candidate1) {
            count1++;
        } else if (el == candidate2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    int mini = n / 3;
    for (int &el : nums) {
        if (el == candidate1) count1++;
        if (el == candidate2) count2++;
    }

    if (count1 > mini) {
        res.push_back(candidate1);
    }
    if (count2 > mini) {
        res.push_back(candidate2);
    }

    sort(res.begin(), res.end());

    return res;
}

int main() {
    return 0;
}