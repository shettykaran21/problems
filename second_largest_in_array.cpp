#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Sort array
    -> Traverse from right and find the first el from right != largest element

    Time - O(n*logn) + O(n) (Sort + Entire array traversal in worst case)
    Space - O(1)
*/
int solve_1(vector<int> &v) {
    sort(v.begin(), v.end());

    int n = v.size();
    int largest = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (v[i] != largest) {
            return v[i];
        }
    }

    return -1;
}

/*
    Better
    -> Traverse once to find largest element
    -> Traverse second time to find element != largest, but maximum

    Time - O(n) + O(n) (2 traversals)
    Space - O(1)
*/
int solve_2(vector<int> &v) {
    int largest = *max_element(v.begin(), v.end());

    int second_largest = INT_MIN;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > second_largest && v[i] != largest) {
            second_largest = v[i];
        }
    }

    return second_largest;
}

/*
    Optimal
    -> If the current_element > largest => then update second_largest and largest
    -> Else if the current_element > second_largest => then we update second_largest

    Time - O(n)
    Space - O(1)
*/
int solve_3(vector<int> &v) {
    int n = v.size();
    int largest = v[0], second_largest = -1;

    for (int i = 1; i < n; ++i) {
        if (v[i] > largest) {
            second_largest = largest;
            largest = v[i];
        } else if (v[i] < largest && v[i] > second_largest) {
            second_largest = v[i];
        }
    }

    return second_largest;
}

int main() {
    vector<int> v = {1, 2, 4, 7, 7, 5};

    cout << solve_3(v) << '\n';

    return 0;
}