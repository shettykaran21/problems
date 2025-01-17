#include <bits/stdc++.h>

using namespace std;

void printIntervals(vector<vector<int>>& intervals) {
    for (auto& interval : intervals) {
        cout << "{" << interval[0] << "," << interval[1] << "} ";
    }
    cout << '\n';
}

/*
    -> Select i-th element, check if it's overlapping for next j elements
        -> If overlapping, merge the intervals
        -> If not, break from inner j loop

    Time - O(nlogn) + O(2n)
    Space - O(n)
*/
vector<vector<int>> solve_1(vector<vector<int>>& intervals) {
    int n = intervals.size();

    vector<vector<int>> ans;

    // Sort
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; ++i) {
        int start = intervals[i][0], end = intervals[i][1];

        // Skip merged intervals
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        // Check rest of intervals
        for (int j = i + 1; j < n; ++j) {
            if (intervals[j][0] <= end) {
                // overlapping
                end = max(end, intervals[j][1]);
            } else {
                // not overlapping
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

/*

*/
vector<vector<int>> solve_2(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= ans.back()[1]) {
            // overlapping
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        } else {
            // not overlapping
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {2, 4}, {8, 9}, {9, 11}};

    printIntervals(intervals);

    auto op = solve_2(intervals);

    printIntervals(op);

    return 0;
}