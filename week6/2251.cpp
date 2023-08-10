#include <bits/stdc++.h>
using namespace std;
int A, B, C;
bool tmp[201][201][201];
vector<int> ans;
void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, C});
    while (!q.empty())
    {
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        if (tmp[a][b][c])
            continue;
        tmp[a][b][c] = true;

        if (a == 0)
            ans.push_back(c);

        if (a + b > B)
            q.push({a + b - B, B, c});
        else
            q.push({0, a + b, c});

        if (a + c > C)
            q.push({a + b - C, b, C});
        else
            q.push({0, b, a + c});

        if (b + a > A)
            q.push({A, b + a - A, c});
        else
            q.push({b + a, 0, c});

        if (b + c > C)
            q.push({a, b + c - C, C});
        else
            q.push({a, 0, b + c});

        if (c + a > A)
            q.push({A, b, c + a - A});
        else
            q.push({c + a, b, 0});

        if (c + b > B)
            q.push({a, B, c + b - B});
        else
            q.push({a, c + b, 0});
    }
    return;
}
int main()
{
    cin >> A >> B >> C;

    bfs();

    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << ' ';
    }
}