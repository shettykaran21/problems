#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &pages, int students, int maxPages) {
    int noOfStudentsAllocated = 0;
    long pagesAllocatedToCurrentStudent = 0;

    for (int &page : pages) {
        if (pagesAllocatedToCurrentStudent + page > maxPages) {
            noOfStudentsAllocated++;
            pagesAllocatedToCurrentStudent = page;
        } else {
            pagesAllocatedToCurrentStudent += page;
        }
    }
    noOfStudentsAllocated++;

    return noOfStudentsAllocated <= students;
}

int solve(vector<int> &pages, int students) {
    if (pages.size() < students) return -1;

    int low = *max_element(pages.begin(), pages.end()), high = accumulate(pages.begin(), pages.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, students, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}