#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Insert elements in set
    -> Replace elements in original array

    Time - O(nlogn) + O(n) => (Insert n elements in set + Array traversal)
    Space - O(n)
*/
int solve_1(vector<int> &v) {
    set<int> s;

    for (int &el : v) {
        s.insert(el);
    }

    int i = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        v[i++] = *it;
    }

    return s.size();
}

/*
    Optimal
    -> Traverse from 2nd element
    -> If v[i] != last unique element => insert v[i]
    x
 */
int solve_2(vector<int> &v) {
    int n = v.size();

    int last_unique_el_indx = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] != v[last_unique_el_indx]) {
            ++last_unique_el_indx;
            v[last_unique_el_indx] = v[i];
        }
    }

    return last_unique_el_indx + 1;
}

int main() {
    return 0;
}