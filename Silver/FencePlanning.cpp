#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[100000];
bool vis[100000];
pair<int, int> coords[100000];
vector<int> c;
vector<vector<int>> components;

void dfs(int s){
    c.push_back(s);
    vis[s] = true;
    for(int v : adj[s]){
        if(!vis[v]) dfs(v);
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> N >> M;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        coords[i] = {a, b};
    }
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        dfs(i);
        components.push_back(c);
        c.clear();
    }
    
    int mindp = INT_MAX;
    int maxX = 0, minX = INT_MAX, maxY = 0, minY = INT_MAX;
    for(vector<int> v : components){
        for(int u : v){
            maxX = max(maxX, coords[u].first);
            minX = min(minX, coords[u].first);
            maxY = max(maxY, coords[u].second);
            minY = min(minY, coords[u].second);
        }
        mindp = min(mindp, 2 * (maxX-minX) + 2 * (maxY-minY));
        maxX = 0;
        maxY = 0;
        minX = INT_MAX;
        minY = INT_MAX;
    }
    cout << mindp;
}