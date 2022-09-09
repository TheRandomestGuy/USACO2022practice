#include <bits/stdc++.h>

using namespace std;

int N, K;
int practiceSessionScores[10][20];

bool better (int cow1, int cow2, int pracSes){
    int cow1Pos, cow2Pos;
    for(int i = 0; i < N; i++) {
        if(practiceSessionScores[pracSes][i] == cow1){ cow1Pos = i;}
        if(practiceSessionScores[pracSes][i] == cow2){ cow2Pos = i;}
    }
    return cow1Pos > cow2Pos;
}

bool betterAllSets(int cow1, int cow2){
    int cow1BetterNum = 0;
    for(int i = 0; i < K; i++){
        if(better(cow1, cow2, i)){cow1BetterNum++;}
    }
    if(cow1BetterNum == K) return true;
    else return false;
}

int main(void){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> K >> N;
    for (int k=0; k<K; k++)
        for (int n=0; n<N; n++) 
            cin >> practiceSessionScores[k][n];
    int answer = 0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if(betterAllSets(i,j)) answer++;
    cout << answer;        
}