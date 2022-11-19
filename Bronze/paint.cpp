#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool fence[100];
    for(int i = 0; i < 100; i++){
        if(i >= a && i < b){
            fence[i] = true;
        } else if(i >= c && i < d){
            fence[i] = true;
        } else{
            fence[i] = false;
        }
        
    }
    int ans = 0;
    for(int i = 0; i < 100; i++){
        if(fence[i]){
            ans++;
        }
    }
    cout << ans;
}