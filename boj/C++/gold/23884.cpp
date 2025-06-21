#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> index;
    priority_queue<int> maxHeap;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        index[arr[i]] = i;
        maxHeap.push(arr[i]);
    }

    for (int last = n - 1; k--; last--) {
        if (last == 0) {
            cout << -1;
            return 0;
        }

        int m = maxHeap.top(), lastElem = arr[last];
        maxHeap.pop();

        if (index[m] == last) {
            k++;
            continue;
        }

        swap(arr[index[m]], arr[last]);
        index[lastElem] = index[m];
        index[m] = last;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;
}