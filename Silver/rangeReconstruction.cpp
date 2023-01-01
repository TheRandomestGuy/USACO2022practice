#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> r;
vector<int> temp;

int main() {
    cin >> N;
    int a;
    for(int i = 0; i < N; i++){
        for(int j = N - i; j > 0; j--){
            cin >> a;
            temp.push_back(a);
        }
        r.push_back(temp);
        temp.clear();
    }
    vector<pair<int, int>> ans(N);
    ans[0] = {0, 0};
    ans[1] = {r[0][1], r[0][1]};
    int rlo = 0;
    int rhi = r[0][1];
    for(int i = 2; i < N; i++){
        ans[i] = {rhi - r[0][i], rlo + r[0][i]};
    }    
    for(int i = 1; i < N - 1; i++){
        rhi = ans[i].second; rlo = ans[i].first;
        for(int j = 1; j <= N - i - 1; j++){
            if(j==)
            ans[j + i] = {max(rhi - r[i][j], ans[j + i].first), min(ans[j + i].second, rlo + r[i][j])};
            rhi = ans[j + i].second; rlo = ans[j + i].first;
        }
    }
    for(int i = 0; i < N; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
