#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W;  // Maximum weight capacity of the knapsack
    int n;  // Number of items

    // Input number of items and maximum weight
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity: ";
    cin >> W;

    vector<int> weights(n);
    vector<int> values(n);

    // Input weights and values of the items
    cout << "Enter weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    cout << "Enter values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // Solve the 0/1 knapsack problem
    int maxValue = knapsack(W, weights, values);

    // Output the maximum value that can be achieved
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
