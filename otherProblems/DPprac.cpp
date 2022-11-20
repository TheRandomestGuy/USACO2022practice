#include <bits/stdc++.h>

using namespace std;

int grid[100][100];
int ans[100][100];

int findPaths(int row, int col){
    if(row == 0 && col == 0){
        ans[row][col] = grid[row][col];
        return ans[row][col];
    }
    
    if(ans[row][col] != 0) return ans[row][col];

    if(row == 0) ans[row][col] = ans[row][col-1] + grid[row][col];
    if(col == 0) ans[row][col] = ans[row-1][col] + grid[row][col];
    if(ans[row][col] == 0) ans[row][col] = min(ans[row][col-1], ans[row-1][col]) + grid[row][col];

    return ans[row][col];
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[j][i];
        }    
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            findPaths(j, i);
        }    
    }

    cout << findPaths(N-1, N-1) << endl;
}