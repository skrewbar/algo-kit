#include <bits/stdc++.h>
using namespace std;

int k;
int visitedCnt = 0;

vector<int> visitOrder;
vector<vector<int>> nodesOfLevel;

void dfs(int level) {
    if (level <= k) {
        dfs(level + 1);
        nodesOfLevel[level].push_back(visitOrder[++visitedCnt]);
        dfs(level + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    visitOrder = vector<int>(1 << k);
    for (int i = 1; i < (int)visitOrder.size(); i++)
        cin >> visitOrder[i];

    nodesOfLevel = vector(k + 1, vector<int>());
    dfs(1);

    for (int i = 1; i <= k; i++) {
        for (int building : nodesOfLevel[i])
            cout << building << ' ';
        cout << '\n';
    }

    return 0;
}