#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<bool>> grid;
vector<int> t(1000, -1);
vector<vector<int>> color(1000, t);
vector<pair<int, int>> blobs;

int floodfill(int row, int col, int clr){
	if(((row < 0 || row >= N || col < 0 || col >= N) || !grid[row][col])) return 0;
    if(color[row][col] != -1) return 1;

	color[row][col] = clr;
    blobs[clr].first++;
    if(floodfill(row, col + 1, clr) == 0) blobs[clr].second++; 
    if(floodfill(row, col - 1, clr) == 0) blobs[clr].second++; 
    if(floodfill(row + 1, col, clr) == 0) blobs[clr].second++; 
    if(floodfill(row - 1, col, clr) == 0) blobs[clr].second++; 
    return 2;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    vector<bool> temp;
    char a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a;
            if(a == '#') temp.push_back(true);
            else temp.push_back(false);
        }
        grid.push_back(temp);
        temp.clear();
    }

    int clr = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(color[i][j] == -1 && grid[i][j]){
                blobs.push_back({0, 0});
                floodfill(i, j, clr);
                clr++;
            }
        }
    }
    sort(begin(blobs), end(blobs));
    cout << blobs[clr-1].first << " " << blobs[clr-1].second;
}