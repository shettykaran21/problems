#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    Iterate through entire matrix and search for target

    Time - O(n * m)
    Space - O(1)
*/

/*
    Optimal 1
    -> Iterate through rows
    -> If target >= first el of row && target <= last element of row, binary search the row

    Time - O(n) * O(logm) - where n is the no of rows and m is the no of columns
    Space - O(1)

    The time complexity is as good as O(n) because the condition will be true only once, so binary search will only be performed once
*/
bool solve_1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; ++i) {
        if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
            return binary_search(matrix[i].begin(), matrix[i].end(), target);
        }
    }

    return false;
}

/*
    Optimal 2 - Think of the whole matrix as a 1D array
    -> Simple binary search the whole matrix

    Time - O(log(n * m)) - where n is the no of rows and m is the no of columns
    Space - O(1)

    The time complexity is as good as O(n) because the condition will be true only once, so binary search will only be performed once
*/
bool solve_1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0, r = m * n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int el = matrix[mid / m][mid % m];

        if (target < el) {
            r = mid - 1;
        } else if (target > el) {
            l = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    return 0;
}