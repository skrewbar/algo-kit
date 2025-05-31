#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll power(ll base, ll exp) {
    ll ret = 1;
    while (exp) {
        if (exp & 1)
            ret *= base;
        base *= base;
        exp >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> suspicious = {'1', '6', '2', '7'};

    string pw;
    cin >> pw;

    ll k;
    cin >> k;
    k--;

    int suspiciousCnt = 0;
    for (int i = 0; i < (int)pw.size(); i++)
        if (suspicious.contains(pw[i])) {
            suspiciousCnt++;
            if (pw[i] == '6')
                pw[i] = '1';
            else if (pw[i] == '7')
                pw[i] = '2';
        }

    for (int i = 0; i < (int)pw.size(); i++) {
        if (not suspicious.contains(pw[i]))
            continue;

        ll th = power(2, --suspiciousCnt);

        if (k < th)
            continue;

        k -= th;
        if (pw[i] == '1')
            pw[i] = '6';
        else  // if (pw[i] == '2')
            pw[i] = '7';
    }

    if (k != 0) {
        cout << -1;
        return 0;
    }

    cout << pw;
    return 0;
}