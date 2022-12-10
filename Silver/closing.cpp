#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[3000];
int visited[3000];

int main(){
    cin >> N >> M;
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back()
    }
}