#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Insert in set
    -> Convert set to array

    Time - O((m + n)log(m + n)) + O(m + n) (Insertion in set takes n*O(n) time for n elements + Set traversal will take O(n) in worst case)
    Space - O(n + m) (Extra space for set, Ignoring space required for result array)
 */
vector<int> solve_1(vector<int> &a, vector<int> &b) {
    set<int> s;

    for (int &el : a) {
        s.insert(el);
    }
    for (int &el : b) {
        s.insert(el);
    }

    vector<int> res;
    for (auto it = s.begin(); it != s.end(); ++it) {
        res.push_back(*it);
    }

    return res;
}

/*
    Optimal
    -> Two pointers

    Time - O(n + m)
    Space - O(1) (Ignoring space required for result array)
*/
vector<int> solve_2(vector<int> &a, vector<int> &b) {
    vector<int> res;

    int i = 0, j = 0;
    int n1 = a.size(), n2 = b.size();

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (res.size() == 0 || res.back() != a[i]) {
                res.push_back(a[i]);
            }

            i++;
        } else if (a[i] > b[j]) {
            if (res.size() == 0 || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        } else {
            if (res.size() == 0 || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n1) {
        if (res.back() != a[i]) {
            res.push_back(a[i]);
        }
        i++;
    }
    while (j < n2) {
        if (res.back() != b[j]) {
            res.push_back(b[j]);
        }
        j++;
    }

    return res;
}

int main() {
    return 0;
}