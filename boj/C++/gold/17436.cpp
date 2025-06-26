#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> primes(n);
    for (int i = 0; i < n; i++)
        cin >> primes[i];

    ll answer = 0;
    for (int k = 1; k < (1 << n); k++) {
        ll product = 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (k & (1 << i)) {
                count++;
                product *= primes[i];
            }
        }

        if (count & 1)
            answer += m / product;
        else
            answer -= m / product;
    }

    print("{}", answer);

    return 0;
}