#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int t = i;
        for (int j = t - 1; j >= 0 and gcd(a[t], a[j]) == 1; j--) {
            if (a[t] < a[j]) {
                for (int k = t; k > j; k--)
                    swap(a[k], a[k - 1]);
                t = j;
            }
        }
    }

    for (int e : a)
        cout << e << ' ';
}