#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll m;
struct Answer {
    ll x, y, v;
    Answer(ll x, ll y) : x(x), y(y), v((1LL << x) + (1LL << y)) {}

    bool operator<(const Answer& a) const {
        if (abs(m - v) != abs(m - a.v))
            return abs(m - v) < abs(m - a.v);
        return v < a.v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;

        Answer answer(62, 62);
        for (int x = 0; x <= 62; x++) {
            for (int y = x; y <= 62; y++) {
                answer = min(answer, Answer(x, y));
            }
        }

        print("{} {}\n", answer.x, answer.y);
    }

    return 0;
}