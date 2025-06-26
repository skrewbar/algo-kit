#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, id;

    bool operator<(const Point& p) const {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y, id] = points[i];
        id = i + 1;
        cin >> x >> y;
    }
    sort(points.begin(), points.end());

    Point& lowest = points.front();
    for (int i = 1; i < n; i++) {
        if (lowest.x != points[i].x) {
            print("{} {}\n", lowest.id, points[i].id);
            lowest = points[i];
            continue;
        }

        print("{} {}\n", points[i - 1].id, points[i].id);
    }

    return 0;
}