#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> puddles(n);
    for (auto& [start, end] : puddles)
        cin >> start >> end;

    ranges::sort(puddles);

    int answer = 0;
    int plankEnd = -1;
    for (auto [start, end] : puddles) {
        plankEnd = max(plankEnd, start - 1);
        while (plankEnd < end - 1) {
            plankEnd += l;
            answer++;
        }
    }

    cout << answer;
}