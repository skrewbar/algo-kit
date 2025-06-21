#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 987'654'321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector(10, 0));
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;

            if (j - 1 > 0) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (j - 2 > 0) {
                dp[i][j] += dp[i - 1][j - 2];
                dp[i][j] %= MOD;
            }

            if (j + 1 <= 9) {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
            if (j + 2 <= 9) {
                dp[i][j] += dp[i - 1][j + 2];
                dp[i][j] %= MOD;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 9; i++)
        answer = (answer + dp[n][i]) % MOD;
    cout << answer;

    return 0;
}