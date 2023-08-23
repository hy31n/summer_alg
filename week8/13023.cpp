#include<iostream>
#iostream<vector>

using namespace std;

static vector<vector <int>> a;
static vector<bool> visited;
static bool arrive;
int main(){
    int n, m;
    arrive = false;
    cin >> n >> m;
    a.resize(n);
    visited = vector<bool>(n, false);

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        a[s].push_back(e); // 양뱡향 저장
        a[e].push_back(s);
    }

    for(int i = 0; i < n; i++){
        dfs(i, 1);
        if(arrive) break;
    }

    if(arrive){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}

void dfs(int now, int depth){
    if(depth == 5 && arrive){
        arrive = true;
        return;
    }
    visited[now] = true;

    for(int i : a[now]){ // i와 연결된 모든 노드들
        if(!visited[i]){
            dfs(i, depth + 1);
        }
    }
    visited[now] = false;
}