#include <bits/stdc++.h>
using namespace std;

int p, m;

struct Player {
    int level;
    string name;
};

struct Room {
    int lo, hi;
    vector<Player> players;
    Room(const Player& p) : lo(p.level - 10), hi(p.level + 10) {
        players.push_back(p);
    }

    bool addPlayer(const Player& p) {
        if (players.size() == m)
            return false;
        players.push_back(p);
        return true;
    }

    void printRoom() {
        if (players.size() == m)
            print("Started!\n");
        else
            print("Waiting!\n");
        ranges::sort(players, ranges::less(), &Player::name);
        for (auto [level, name] : players)
            print("{} {}\n", level, name);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> m;
    vector<Room> rooms;
    for (int i = 0; i < p; i++) {
        Player p;
        cin >> p.level >> p.name;

        bool joined = false;
        for (Room& room : rooms) {
            if (room.lo <= p.level and p.level <= room.hi) {
                if (room.addPlayer(p)) {
                    joined = true;
                    break;
                }
            }
        }

        if (not joined)
            rooms.emplace_back(p);
    }

    for (Room& room : rooms)
        room.printRoom();
}