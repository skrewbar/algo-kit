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

    int answer = 0;
    for (int choices = 1; choices < (1 << n); choices++) {
        bool resent = false;
        Hand beforeHand = handMap[first];
        Winner beforeWinner = DRAW;
        for (int i = 0; i < n; i++) {
            if (~choices & (1 << i))
                continue;

            Hand nowHand = handMap[s[i]];
            Winner nowWinner = getWinner(beforeHand, nowHand);

            if (nowWinner == DRAW and beforeWinner == LIGHTER) {
                resent = true;
                break;
            }

            swap(beforeHand, nowHand);
            swap(beforeWinner, nowWinner);
        }

        answer += not resent;
    }

    print("{}", answer % MOD);

    return 0;
}