#include <bits/stdc++.h>

using namespace std;
int ans[100];
int main(){
    int N;
    cin >> N;

    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i <= N; i++){
        ans[i] += ans[i-1];
        ans[i] += ans[i-2];
        cout << ans[i] << endl;
    }
}