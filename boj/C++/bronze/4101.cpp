#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    while (a || b) {
        if (a > b)
            cout << "Yes\n";
        else
            cout << "No\n";
        cin >> a >> b;
    }
}