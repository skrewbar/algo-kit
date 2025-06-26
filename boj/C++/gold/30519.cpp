#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

enum Hand { ROCK = 0, PAPER = 1, SCISSORS = 2 };

Hand getBeatingHand(Hand hand) {
    return Hand((hand + 1) % 3);
}

enum Winner { LIGHTER, SMALLANT, DRAW };

Winner getWinner(Hand lighter, Hand smallant) {
    if (getBeatingHand(lighter) == smallant)
        return SMALLANT;
    else if (getBeatingHand(smallant) == lighter)
        return LIGHTER;
    return DRAW;
}

map<char, Hand> handMap = {
    {'R', ROCK},
    {'P', PAPER},
    {'S', SCISSORS},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char first;
    string s;
    cin >> first >> s;

    int n = s.size();

    vector<vector<int>> dp(3, vector(3, 0));

    Hand firstHand = Hand(handMap[first]);
    for (int i = 0; i < n; i++) {
        auto newDp(dp);

        Hand now = handMap[s[i]];
        for (int handInt = 0; handInt < 3; handInt++) {
            Hand before = Hand(handInt);
            Winner winner = getWinner(before, now);

            newDp[now][winner] +=
                (dp[before][DRAW] + dp[before][SMALLANT]) % MOD;
            newDp[now][winner] %= MOD;
            if (winner != DRAW) {
                newDp[now][winner] += dp[before][LIGHTER];
                newDp[now][winner] %= MOD;
            }
        }

        Winner firstWinner = getWinner(firstHand, now);
        newDp[now][firstWinner]++;
        newDp[now][firstWinner] %= MOD;

        swap(newDp, dp);
    }

    int answer = 0;
    for (int hand = 0; hand < 3; hand++)
        for (int winner = 0; winner < 3; winner++)
            answer = (answer + dp[hand][winner]) % MOD;

    print("{}", answer);

    return 0;
}