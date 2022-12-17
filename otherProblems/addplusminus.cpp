#include <bits/stdc++.h>

using namespace std;

int T;
int N;
string A;
int main(){
    cin >> T;
    int total = 0;
    string ans = "";
    for(int i = 0; i < T; i++){
        cin >> N; 
        cin >> A;
        if(A[0] == '1'){
            total = 1;
        }
        for(int j = 1; j < N; j++){
            if(A[j] == '1'){
                if(total > 0){
                    ans += "-";
                    total--;
                } else{
                    ans += "+";
                    total++;
                }
            } else{
                ans+="+";
            }
        }
        cout << ans << endl;
        ans = "";
        total = 0;
    }
}