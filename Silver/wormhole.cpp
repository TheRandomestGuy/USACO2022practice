#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> cows;
vector<vector<pair<int, int>>> adj(100000);
vector<int> vis(100000, -1);

void dfs(int s, int w, int g){
    vis[s] = g;
    for(pair<int, int> v : adj[s]){
        if(v.second < w) continue;
        if(vis[v.first] == -1) dfs(v.first, w, g);
    }
}

bool check(int k){
    vis.assign(100000, -1);
	for (int i = 0; i < N; i++){
		if (vis[i] != -1) continue;
		dfs(i, k, i);
	}
	for (int i = 0; i < N; i++){
		if (vis[cows[i]] != vis[i]){
			return false;
		}
	}
	return true;
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    cin >> N >> M;
    int a, b = -1;
    bool sorted = true;
    int mw = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        a--;
        cows.push_back(a);
        sorted = a > b && sorted;
        b = a;
    }

    if(sorted){
        cout << -1;
        return 0;
    }

    int c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--; b--;
        mw = max(mw, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int low = 0, high = mw;
    int mid;
    while(low < high){
        mid = (low + high + 1) / 2;
        if(check(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low;
}