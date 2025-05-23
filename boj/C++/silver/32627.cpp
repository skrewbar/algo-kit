#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    for (char alphabet : "abcdefghijklmnopqrstuvwxyz") {
        for (int i = 0; i < n; i++) {
            if (s[i] == alphabet) {
                s[i] = '\0';
                m--;
            }

            if (m == 0)
                break;
        }
        if (m == 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '\0')
            continue;
        cout << s[i];
    }
}