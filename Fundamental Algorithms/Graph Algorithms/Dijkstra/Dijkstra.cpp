#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;

int n, m;
vector<pair<int, int>> G[N];
int dis[N];

void dijkstra() {
    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }

    dis[1] = 0;
    s.insert({0, 1});

    while (!s.empty()) {
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + w) {
                if (dis[v] != INF) {
                    s.erase({dis[v], v});
                }
                dis[v] = dis[u] + w;
                s.insert({dis[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << '\n';
}
