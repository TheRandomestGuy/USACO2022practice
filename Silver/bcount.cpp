#include <bits/stdc++.h>

using namespace std; 


int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;

    cin >> N >> Q;

    int cows[N][3];
    int prefix[N+1][3];

    prefix[0][0] = 0;
    prefix[0][1] = 0;
    prefix[0][2] = 0;

    int a;
    for(int i = 1; i <= N; i++){
        cin >> a;
        prefix[i][0] = prefix[i-1][0];
        prefix[i][1] = prefix[i-1][1];
        prefix[i][2] = prefix[i-1][2];

        prefix[i][a-1]++;
    }
    int b;
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        a--;
        cout << prefix[b][0] - prefix[a][0] << " " << prefix[b][1] - prefix[a][1] << " " << prefix[b][2] - prefix[a][2] << endl;
    }
}