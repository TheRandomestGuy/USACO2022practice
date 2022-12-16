#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[3000];
int visited[3000][3000];
int closed[3000];
vector<int> closing;
int c = 0;

int dfs(int start, int org){
    visited[start][org] = true;
    for(int a : adj[start]){
        if(!visited[a][org] && !closed[a]){
            visited[a][org] = true;
            dfs(a, org);
            c++;
        }
    }
    return c + 1;
}

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> N >> M;
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        cin >> a;
        closing.push_back(a);
    }

    if(dfs(closing[N-1], 0) == N){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    for(int i = 0; i < N-1; i++){
        closed[closing[i]] = true;
        c = 0;
        if(dfs(closing[N-1], closing[i]) == N - i - 1){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}