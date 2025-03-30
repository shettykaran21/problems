#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &v) {
    int n = v.size();
    int rotation_points = 0;

    for (int i = 1; i < n; ++i) {
        if (v[i] >= v[i - 1]) {
            continue;
        } else {
            rotation_points++;

            if (rotation_points > 1) return false;
        }
    }

    if (rotation_points == 0) return true;

    if (rotation_points == 1 && v[0] >= v[n - 1]) return true;

    return false;
}

int main() {
    vector<int> v = {3, 4, 5, 1, 2};
    cout << solve(v) << '\n';

    return 0;
}