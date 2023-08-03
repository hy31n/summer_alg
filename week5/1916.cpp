#include <stdio.h>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
 
int main()
{
    int N, M, x, y, cost;
    vector<pair<int, int>> adj[1001];
 
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &x, &y, &cost);
        adj[x].push_back({y, cost});
    }
    scanf("%d %d", &x, &y);

    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty())
    {
        int cost = pq.top().first * -1;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost)
            continue;
        int size = adj[here].size();
        for (int i = 0; i < size; i++)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
 
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({nextDist * -1, there});
            }
        }
    }
    printf("%d\n", dist[y]);
    return (0);
}