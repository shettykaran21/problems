#include <bits/stdc++.h>

using namespace std;

/*
    Brute force - Three pointers

    Time - O(n + m) + O(n + m)
    Space - O(n + m)
*/
void solve_1(vector<int> &nums1, vector<int> &nums2) {
    int i = 0, j = 0, k = 0;
    int n = nums1.size(), m = nums2.size();

    vector<int> temp(n + m);

    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            temp[k++] = nums1[i++];
        } else {
            temp[k++] = nums2[j++];
        }
    }

    while (i < n) {
        temp[k++] = nums1[i++];
    }

    while (j < m) {
        temp[k++] = nums2[j++];
    }

    i = 0;
    while (i < n) {
        nums1[i] = temp[i];
        i++;
    }
    while (i < n + m) {
        nums2[i - n] = temp[i];
        i++;
    }
}

/*
    Optimal 1 - Swap and sort

    -> i = n - 1, j = 0
    -> ith > jth ? swap elements i.e. move bigger elements to second array and smaller elements to first
    -> Sort both arrays at the end

    Time - O(min(n, m)) + O(nlogn) + O(mlogm)
    Space - O(1)
*/
void solve_2(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    int i = n - 1, j = 0;

    while (i >= 0 && j < m) {
        if (nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        } else {
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

/*
    Optimal 2 - Gap Method (Shell Sort)

    -> gap = (n + m + 1) / 2
    -> while (gap > 0)
        -> l = 0, r = l + gap
        -> lth el > rth el ? swap elements
    -> gap = (gap + 1) / 2

    Time - O(log(n + m)) * O(n + m)
    Space - O(1)
*/
void solve_3(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    int gap = (n + m + 1) / 2;

    while (gap > 0) {
        int l = 0, r = l + gap;

        while (r < n + m) {
            // l on nums1, r on nums2
            if (l < n && r >= n) {
                if (nums1[l] > nums2[r - n]) {
                    swap(nums1[l], nums2[r - n]);
                }
            }
            // l on nums2, r on nums2
            else if (l >= n) {
                if (nums2[l - n] > nums2[r - n]) {
                    swap(nums2[l - n], nums2[r - n]);
                }
            }
            // l on nums1, r on nums1
            else {
                if (nums1[l] > nums1[r]) {
                    swap(nums1[l], nums1[r]);
                }
            }

            l++;
            r++;
        }

        if (gap == 1) break;

        gap = (gap + 1) / 2;
    }
}

int main() {
    vector<int> nums1 = {0, 1, 3, 6, 8};
    vector<int> nums2 = {0, 4, 4, 4, 7, 9};

    solve_3(nums1, nums2);

    for (auto &el : nums1) {
        cout << el << " ";
    }
    for (auto &el : nums2) {
        cout << el << " ";
    }

    return 0;
}