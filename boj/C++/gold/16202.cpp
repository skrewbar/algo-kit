#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent;

    DisjointSet(size_t size) : parent(size) {
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int findParent(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = findParent(parent[v]);
    }

    void unionParent(int u, int v) { parent[findParent(u)] = findParent(v); }
};

struct Edge {
    int from, to, weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    stack<Edge> temp;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        temp.emplace(from, to, i);
    }
    stack<Edge> edgeStack;
    while (not temp.empty())
        edgeStack.push(temp.top()), temp.pop();

    for (int turn = 0; turn < k; turn++) {
        int mstCost = 0;

        DisjointSet disjointSet(n + 1);
        stack<Edge> temp;

        for (int edgeCnt = 0; edgeCnt < n - 1;) {
            if (edgeStack.empty()) {
                mstCost = 0;
                break;
            }

            Edge edge = edgeStack.top();
            temp.push(edge);
            edgeStack.pop();

            if (disjointSet.findParent(edge.from) ==
                disjointSet.findParent(edge.to))
                continue;

            disjointSet.unionParent(edge.from, edge.to);
            mstCost += edge.weight;
            edgeCnt++;
        }

        while (not temp.empty()) {
            edgeStack.push(temp.top());
            temp.pop();
        }

        if (not edgeStack.empty())
            edgeStack.pop();

        cout << mstCost << ' ';
    }

    return 0;
}