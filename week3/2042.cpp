#include <iostream>
using namespace std;

int N, M, K;
long long tree[1 << 21];

void update(int node, int start, int end, int idx, long long data)
{
    int m;
    if (start == end)
    {
        tree[node] = data;
        return;
    }
    m = (start + end) / 2;
    if (idx <= m)
        update(node * 2, start, m, idx, data);
    else
        update(node * 2 + 1, m + 1, end, idx, data);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int qs, int qe)
{
    int m;
    if (end < qs || qe < start)
        return 0;
    if (qs <= start && end <= qe)
        return tree[node];

    m = (start + end) / 2;
    return query(node * 2, start, m, qs, qe) + query(node * 2 + 1, m + 1, end, qs, qe);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    long long a, b, c;

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        update(1, 1, N, i, num);
    }

    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, N, b, c);
        else
            cout << query(1, 1, N, b, c) << "\n";
    }

    return 0;
}