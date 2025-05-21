#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 2) {
        cout << min((m - 1) >> 1, 3) + 1;
        return 0;
    }

    if (m < 7) {
        cout << min(m - 1, 3) + 1;
        return 0;
    }

    cout << 4 + m - 7 + 1;
}