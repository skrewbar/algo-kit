#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> len(n);
    for (int i = 1; i < n; i++)
        cin >> len[i];
    vector<ll> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    ll minPrice = price[0];
    ll totalCost = 0;
    for (int i = 1; i < n; i++) {
        totalCost += len[i] * minPrice;
        minPrice = min(minPrice, price[i]);
    }

    cout << totalCost;
}