#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer = 0;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        answer += num * num;
    }
    cout << answer % 10;
}