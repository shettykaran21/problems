#include <bits/stdc++.h>

using namespace std;

/*
    Brute

    Time - O(n^2)
    Space - O(1)
*/
int solve_1(vector<int> &prices) {
    int maxi_profit = 0;
    int n = prices.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[j] > prices[i]) {
                maxi_profit = max(maxi_profit, prices[j] - prices[i]);
            }
        }
    }

    return maxi_profit;
}

/*
    Optimal

    Time - O(n^2)
    Space - O(1)
*/
int solve_2(vector<int> &prices) {
    int n = prices.size(), mini = prices[0];
    int maxi_profit = INT_MIN;

    for (int &el : prices) {
        mini = min(mini, el);
        maxi_profit = max(maxi_profit, el - mini);
    }

    return maxi_profit;
}

int main() {
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << solve_1(prices) << '\n';

    return 0;
}