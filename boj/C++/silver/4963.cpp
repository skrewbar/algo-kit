#include <bits/stdc++.h>
using namespace std;

array<int, 8> dx = {1, 1, 0, -1, -1, -1, 0, 1};
array<int, 8> dy = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 and h == 0)
            break;

        vector<vector<int>> ground(h, vector<int>(w));

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> ground[i][j];

        vector<vector<bool>> visited(h, vector(w, false));
        int answer = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j] or not ground[i][j])
                    continue;

                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (not q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 8; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (0 <= nx and nx < h and 0 <= ny and ny < w and
                            ground[nx][ny] and not visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.emplace(nx, ny);
                        }
                    }
                }
                answer++;
            }
        }
        cout << answer << '\n';
    }
}