#include <bits/stdc++.h>

using namespace std;

/*
    Brute
    -> Copy last k elements in temp array
    -> Shift n - k elements to the left
    -> Copy elements from temp array to original array

    Time - O(n)
    Space - O(n)
 */

/*
    Optimal
    -> Reverse elements in range [0, n - k]
    -> Reverse elements in range [n - k, n]
    -> Reverse entire array

    Time - O(n - k) + O(k) + O(n) => O(2n)
    Space - O(1)
*/
void solve(vector<int> &v, int k) {
    int n = v.size();
    k = k % n;

    reverse(v.begin(), v.begin() + n - k);
    reverse(v.begin() + n - k, v.end());
    reverse(v.begin(), v.end());
}

int main() {
    return 0;
}