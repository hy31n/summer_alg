#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[20001];
vector<vector<pair<int, int>>> way;

int main() {
    
    int v, e, k;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;

    priority_queue<pair<int, int>> pq;

    cin >> v >> e;
    cin >> k;
    way.resize(v + 1);
    for (int i = 0; i < e; i++) {
        cin >> city_a >> city_b >> cost;
        way[city_a].push_back(make_pair(city_b, cost));
    }

    for (int i = 1; i <= v; i++) {
        dist[i] = -1;
    }

    dist[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        cost = -1 * pq.top().first;
        here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < way[here].size(); i++) {

            there = way[here][i].first;
            nextCost = cost + way[here][i].second;

            if (dist[there] == -1) {
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));
            } else if (nextCost < dist[there]) {
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));
            }
        }
    }
    
    for (int i = 1; i <= v; i++) {
        if (dist[i] == -1)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
