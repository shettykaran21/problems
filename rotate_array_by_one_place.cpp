#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &v) {
    int n = v.size();

    if (n == 1) return;

    int temp = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        v[i + 1] = v[i];
    }

    v[0] = temp;
}

int main() {
    return 0;
}