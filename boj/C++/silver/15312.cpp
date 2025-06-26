#include <bits/stdc++.h>
using namespace std;

int stroke[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2,
                  2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    vector<int> sum(a.size() + b.size());
    for (int i = 0; i < (int)a.size(); i++) {
        sum[i << 1] = stroke[a[i] - 'A'];
        sum[i << 1 | 1] = stroke[b[i] - 'A'];
    }

    for (int len = sum.size() - 1; len >= 2; len--) {
        for (int i = 0; i < len; i++) {
            sum[i] += sum[i + 1];
            sum[i] %= 10;
        }
    }

    print("{}{}", sum[0], sum[1]);
    return 0;
}