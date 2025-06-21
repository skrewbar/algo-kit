#include <bits/stdc++.h>
using namespace std;

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string tail(const string& s) {
    return s.substr(1);
}

void solve() {
    string s;
    cin >> s;

    string pref = s.substr(0, (s.size() + 3 - 1) / 3);
    cout << ((s == pref + rev(pref) + pref) or
             (s == pref + tail(rev(pref)) + pref) or
             (s == pref + rev(pref) + tail(pref)) or
             (s == pref + tail(rev(pref)) + tail(pref)))
         << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}