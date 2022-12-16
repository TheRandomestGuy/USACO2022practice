#include <bits/stdc++.h>

using namespace std;

int x[200], y[200], p[200];
bool visited[200];
int totalall = 0;

bool reach(int cow1, int cow2){
    if(x[cow1] == 0 || x[cow2] == 0){
        return false;
    }
    return sqrt(pow(x[cow1] - x[cow2],2) + pow(y[cow1] - y[cow2],2)) <= p[cow1];
}

void totalReached(int start){
    totalall++;
    visited[start] = true;
    for(int i = 0; i < 200; i++){
        if(!visited[i] && reach(start, i)){
            totalReached(i);
        }
    }
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> p[i];
    }
    int max = 0;
    int place = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[j] = false;
        }
        totalall = 0;
        totalReached(i);
        if(max < totalall) max = totalall;
    }

    cout << max;
}