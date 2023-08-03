#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ret;
int n, m;
vector<int> v[104];
bool vst[104];

void dfs(int k)
{
    if (k > n)
        return;
    vst[k] = 1;
    for (auto e : v[k])
    {
        if (!vst[e])
        {
            ret++;
            dfs(e);
        }
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << ret;
    return 0;
}