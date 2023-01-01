#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> rooms;
vector<int> ttw;

bool primeCheck(int n){
    if(n <= 3) return true;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> T;
    for(int j = 0; j < T; j++){
        cin >> N;
        int a;
        for(int i = 0; i < N; i++){
            cin >> a;
            rooms.push_back(a);
        }
        int count = 0;
        int lowN = INT_MAX;
        int lowJ = INT_MAX;
        int lowNi = -1;
        int lowJi = -1;
        int i = 0;
        for(int n : rooms){
            if(n % 2 == 0){
                if(n % 4 == 0){
                    ttw.push_back(-1 * n/4);
                    if(lowN > n/4) lowNi = i;
                    lowN = min(lowN, n/4);
                } else{
                    ttw.push_back(n/4);
                    if(lowJ > n/4) lowJi = i;
                    lowJ = min(lowJ, n/4);
                }
            } else{
                if(primeCheck(n)){
                    ttw.push_back(0);
                    if(lowJ > n/4) lowJi = i;
                    lowJ = min(lowJ, 0);
                } else{
                    while(!primeCheck(n)){
                        n -= 4;
                        count++;
                    }
                    ttw.push_back(count);
                    if(lowJ > n/4) lowJi = i;
                    lowJ = min(lowJ, count);
                    count = 0;
                }
            }
            i++;
        }

        if(lowN > lowJ){
            cout << "Farmer John" << endl;
        } else if(lowJ > lowN){
            cout << "Farmer Nhoj" << endl;
        } else{
            if(lowNi > lowJi){
                cout << "Farmer John" << endl;
            } else if(lowJi > lowNi){
                cout << "Farmer Nhoj" << endl;
            } 
        }
        rooms.clear();
        ttw.clear();
    }
}
