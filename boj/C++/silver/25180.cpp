#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int answer = n / 18 * 2;
    n %= 18;
    if (n > 0) {
        if (n < 10)
            answer += 1;
        else
            answer += 2 + (n & 1);
    }

    cout << answer;

    return 0;
}