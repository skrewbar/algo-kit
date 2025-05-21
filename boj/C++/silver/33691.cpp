#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> usedDate;
    unordered_map<string, bool> isPinned;
    vector<string> names;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (not usedDate.contains(name))
            names.push_back(name);

        usedDate[name] = i;
        isPinned[name] = false;
    }

    int k;
    cin >> k;
    while (k--) {
        string name;
        cin >> name;

        isPinned[name] = true;
    }

    ranges::sort(names,
                 [&usedDate, &isPinned](const string& a, const string& b) {
                     if (isPinned[a] ^ isPinned[b])
                         return isPinned[a] > isPinned[b];
                     return usedDate[a] > usedDate[b];
                 });

    for (string& name : names)
        cout << name << '\n';
}