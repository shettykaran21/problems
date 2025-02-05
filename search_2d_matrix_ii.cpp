#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    Iterate through entire matrix and search for target

    Time - O(n * m)
    Space - O(1)
*/

/*
    Better
    -> Iterate through rows
    -> If target >= first el of row && target <= last element of row, binary search the row

    Time - O(n) * O(logm) - where n is the no of rows and m is the no of columns
    Space - O(1)
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
    Optimal
    -> Start from top right
    -> el < target ? row++, el > target ? col--

    Time - O(n + m) - When target is at bottom right
    Space - O(1)
*/
bool solve_2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        int el = matrix[row][col];

        if (el == target) {
            return true;
        } else if (el < target) {
            row++;
        } else {
            col--;
        }
    }

    return false;
}

int main() {
    return 0;
}