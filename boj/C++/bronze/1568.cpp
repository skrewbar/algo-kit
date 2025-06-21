#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int answer = 0;
    for (int k = 1; n > 0; answer++, k++) {
        if (k > n)
            k = 1;
        n -= k;
    }

    cout << answer;
    return 0;
}