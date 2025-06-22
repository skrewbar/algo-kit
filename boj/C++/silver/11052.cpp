#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> price[i];

    vector<int> dp(
        n + 1);  // dp[i] :  카드 i개를 사기 위해 지불해야 하는 금액의 최댓값
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j < 0)
                break;
            dp[i] = max(dp[i], dp[i - j] + price[j]);
        }
    }

    cout << dp[n];
    return 0;
}