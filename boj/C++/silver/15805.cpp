#include <bits/stdc++.h>
using namespace std;

constexpr int NOT_EXIST = -2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n, NOT_EXIST);  // k <= n 이므로
    int node = -1, k = 0;
    for (int i = 0; i < n; i++) {
        int nextNode;
        cin >> nextNode;
        if (parent[nextNode] == NOT_EXIST)
            parent[nextNode] = node;
        node = nextNode;
        k = max(k, node + 1);
    }

    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << parent[i] << ' ';
}