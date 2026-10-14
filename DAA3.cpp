#include<bits/stdc++.h>
using namespace std;

int solve(int i, int capacity, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i == 0 || capacity == 0) return 0;

    if (dp[i][capacity] != -1) return dp[i][capacity];
    int take = 0, ntake = 0;
    if (wt[i-1] <= capacity) {
        take = val[i-1] + solve(i-1, capacity-wt[i-1], wt, val, dp);
    }
    ntake = solve(i-1, capacity, wt, val, dp);
    return dp[i][capacity] = max(take, ntake);
}

int main() {
    string choice;

    while (true) {
        cout << "\n--- 0/1 Knapsack Menu ---\n";
        cout << "1. Solve using Memoization\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "1") {
            int n, capacity;

            cout << "Enter number of items: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid number of items\n";
                continue;
            }

            vector<int> wt(n), val(n);

            cout << "Enter weights of items:\n";
            for (int i = 0; i < n; i++) cin >> wt[i];

            cout << "Enter values of items:\n";
            for (int i = 0; i < n; i++) cin >> val[i];

            cout << "Enter knapsack capacity: ";
            cin >> capacity;

            bool valid = capacity >= 0;
            for (int i = 0; i < n; i++) {
                if (wt[i] <= 0 || val[i] < 0) valid = false;
            }

            if (!valid) {
                cout << "Invalid weights, values, or capacity\n";
                continue;
            }

            vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));

            cout << "Maximum profit: " << solve(n, capacity, wt, val, dp) << endl;
        }
        else if (choice == "2") {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
