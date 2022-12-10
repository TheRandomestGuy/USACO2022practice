#include <bits/stdc++.h>

using namespace std;

int N, K, R;
int fields[100][100];
vector<pair<int, int>> cows;
int road[100][100]; //2 North, 3 East, 5 South, 7 West

void floodfill(int r, int c, int color){
    if(r < 0 || c < 0 || r >= N || c >= N || fields[r][c] == color){
        return;
    }
    fields[r][c] = color;
    if(road[r][c]%3 != 0){
        floodfill(r, c + 1, color);
    }
    if(road[r][c]%2 != 0){
        floodfill(r - 1, c, color);
    }
        if(road[r][c]%7 != 0){
        floodfill(r, c - 1, color);
    }
        if(road[r][c]%5 != 0){
        floodfill(r + 1, c, color);
    }
}

int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> N >> K >> R;
    int a, b, c, d;
    int ans = 0;

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {road[i][j] = 1;}

    for(int i = 0; i < R; i++){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if(a == c){
            if(b > d){
                road[a][b] *= 7; // west
                road[c][d] *= 3; // east
            }
            else {
                road[a][b] *= 3; //east
                road[c][d] *= 7; // west
            }
        } else {
            if(a > c) {
                road[a][b] *= 2; // north
                road[c][d] *= 5; // south
            }
            else {
                road[a][b] *= 5; // south
                road[c][d] *= 2; // north
            }
        }
    }


    for(int i = 0; i < K; i++){
        cin >> a >> b;
        cows.push_back({a - 1, b - 1});
    }

    for(int i = 0; i < K; i ++){
        floodfill(cows[i].first, cows[i].second, i+1);
        for(int j = 0; j < K; j++){
            if(fields[cows[j].first][cows[j].second] == i+1){
                ans++;
            }
        }
    }

    int total = K * (K-1)/2 ;
    cout << (total - (ans - K)/2);
}