#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj(200000);
bool vis[200000];
vector<int> bales;
vector<pair<int, pair<int, int>>> orders;
int trades = 0;
int total = 0;

int dfs(int s){
    int a;
    vis[s] = true;
    for(int v : adj[s]){
        if(!vis[v]){
            a = dfs(v);
            if(a-total != 0) {
                trades++;
                orders.push_back({a - total, {v, s}});
            }
            bales[s] += a - total;
        }
    }
    return bales[s];
}

int main() {
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        total += a;
        bales.push_back(a);
    }
    total = total/N;

    int b;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout << trades << endl;
    sort(orders.rbegin(), orders.rend());
    for(int i = 0; i < trades; i++){
        if(orders[i].first > 0) cout << ++orders[i].second.first << " " << ++orders[i].second.second << " " << orders[i].first << endl;
    }
    sort(orders.begin(), orders.end());
    for(int i = 0; i < trades; i++){
        if(orders[i].first < 0) cout << ++orders[i].second.second << " " << ++orders[i].second.first << " " << -1 * orders[i].first << endl;
    }
}
