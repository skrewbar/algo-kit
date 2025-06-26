#include <bits/stdc++.h>
#include <queue>
using namespace std;

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;

constexpr ll INF = 1LL << 40;

struct Answer {
    int num;
    ll totalCost;

    bool operator<(const Answer& a) const { return totalCost < a.totalCost; }
};

void solve() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> meetings(n);
    for (int i = 0; i < n; i++) {
        cin >> meetings[i];
        meetings[i]--;
    }

    vector<vector<pair<ll, ll>>> adj(p, vector<pair<ll, ll>>());
    while (q--) {
        int i, j, d;
        cin >> i >> j >> d;
        i--, j--;
        adj[i].emplace_back(j, d);
        adj[j].emplace_back(i, d);
    }

    Answer answer(-1, INF);
    for (int i = 0; i < p; i++) {
        vector<ll> cost(p, INF);
        cost[i] = 0;
        vector<bool> reachable(p, false);
        reachable[i] = true;
        minHeap<pair<ll, int>> pq;
        pq.emplace(cost[i], i);

        while (not pq.empty()) {
            auto [nowCost, now] = pq.top();
            pq.pop();

            reachable[now] = true;

            if (nowCost > cost[now])
                continue;

            for (auto [next, edgeCost] : adj[now]) {
                ll nextCost = nowCost + edgeCost;
                if (nextCost < cost[next]) {
                    cost[next] = nextCost;
                    pq.emplace(nextCost, next);
                }
            }
        }

        bool allReachable = true;
        for (int v : meetings)
            allReachable &= reachable[v];
        if (not allReachable)
            continue;

        ll totalCost = 0;
        for (int v : meetings)
            totalCost += cost[v] * cost[v];

        answer = min(answer, Answer(i + 1, totalCost));
    }

    print("{} {}\n", answer.num, answer.totalCost);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}