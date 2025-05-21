#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    ranges::sort(weight);

    bool exists = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (weight[i] == c or weight[i] + weight[j] == c) {
                exists = true;
                break;
            }

            int find = c - weight[i] - weight[j];
            if (find == weight[i] or find == weight[j])
                continue;

            exists = ranges::upper_bound(weight, find) -
                     ranges::lower_bound(weight, find);
            if (exists)
                break;
        }
        if (exists)
            break;
    }

    cout << exists;
}