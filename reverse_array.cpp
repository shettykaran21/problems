#include <bits/stdc++.h>

using namespace std;

/*
    Temp array
    Time - O(n)
    Space - O(n)
*/
void solve_1(vector<int> &nums) {
    vector<int> temp(nums);

    int i = 0, j = temp.size() - 1;

    while (j >= 0) {
        nums[i] = temp[j];
        i++;
        j--;
    }
}

/*
    Two pointers
    Time - O(n)
    Space - O(1)
*/
void solve_2(vector<int> &nums) {
    int i = 0, j = nums.size() - 1;

    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

/*
    Inbuilt method
    Time - O(n)
    Space - O(1)
*/
void solve_3(vector<int> &nums) {
    reverse(nums.begin(), nums.end());
}

void printArray(vector<int> &v) {
    for (int &el : v) {
        cout << el << " ";
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int el;
        cin >> el;
        nums.push_back(el);
    }

    printArray(nums);

    solve_3(nums);

    printArray(nums);

    return 0;
}