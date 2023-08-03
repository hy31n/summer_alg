#include <iostream>
#include <vector>

using namespace std;

int N;
int nodeToRemove;
int answer = 0;
vector<vector<int>> tree;
vector<bool> visited;

void dfs(int cur)
{

    if (0 == tree[cur].size())
    {
        answer++;
        return;
    }

    if (1 == tree[cur].size() && nodeToRemove == tree[cur][0])
    {
        answer++;
        return;
    }

    for (int i = 0; tree[cur].size() > i; i++)
    {
        auto next = tree[cur][i];

        if (!visited[next] && nodeToRemove != next)
        {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main()
{
    cin >> N;

    int root;
    tree.assign(N, vector<int>(0));
    for (int i = 0; N > i; i++)
    {
        int input;
        cin >> input;

        if (-1 == input)
            root = i;
        else
            tree[input].emplace_back(i);
    }

    cin >> nodeToRemove;

    if (nodeToRemove != root)
    {
        visited.assign(N, false);
        visited[root] = true;
        dfs(root);
    }

    cout << answer;

    return 0;
}