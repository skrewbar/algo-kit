#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> voteCnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int vote;
        cin >> vote;
        if (vote == 0)
            continue;
        voteCnt[vote]++;
    }

    int mostVoted = ranges::max_element(voteCnt) - voteCnt.begin();
    bool skip = false;
    for (int i = 0; i <= n; i++) {
        if (i == mostVoted)
            continue;
        if (voteCnt[mostVoted] == voteCnt[i]) {
            skip = true;
            break;
        }
    }

    if (skip)
        cout << "skipped";
    else
        cout << mostVoted;
}