#include <iostream>
#include <queue>

using namespace std;

int m, n;
int arr[1001][1001];
bool visit[1001][1001];

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cnt = 0;

void bfs()
{

    while (!q.empty())
    {
        int qsize = q.size();
        bool result = false;

        for (int i = 0; i < qsize; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (visit[nx][ny])
                    continue;
                if (arr[nx][ny] == 0)
                {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                    result = true;
                }
            }
        }

        if (result == true)
            cnt++;
    }
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                visit[i][j] = true;
            }
            else if (arr[i][j] == -1)
                visit[i][j] = true;
        }

    bfs();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    cout << cnt;
    return 0;
}
