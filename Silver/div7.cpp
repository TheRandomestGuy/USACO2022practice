#include <bits/stdc++.h>

using namespace std;

int N;
int cows[50000];
long long prefix[50001];

void psum(){
    for(int i = 1; i <= N; i++){
        prefix[i] = prefix[i-1] + cows[i-1];
    }
}

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cows[i];
    }
    psum();

    for(int i = N; i > 0; i--){
        for(int j = 0; j <= N-i; j++){
            if((prefix[i + j] - prefix[j]) % 7 == 0){
                cout << i;
                return 0;
            }
        }
    }
}