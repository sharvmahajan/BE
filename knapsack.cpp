#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll i, ll rem, vector<ll>& weights, vector<ll>& values, vector<vector<ll>>& dp){
    if (i >= weights.size()) return 0;
    if (dp[i][rem] != -1) return dp[i][rem];
    ll ntake = solve(i+1, rem, weights, values, dp);
    ll take = 0;
    if (weights[i] <= rem) take = values[i]+solve(i+1, rem-weights[i], weights, values, dp);
    return dp[i][rem] = max(take, ntake);
}

int main(){
    ll n, W;
    cin >> n >> W;

    vector<ll> weights(n), values(n);

    for (ll i = 0; i < n; i++)
        cin >> weights[i] >> values[i];

    vector<vector<ll>> dp(n, vector<ll>(W+1, -1));

    cout << solve(0, W, weights, values, dp) << '\n';

    return 0;
}
