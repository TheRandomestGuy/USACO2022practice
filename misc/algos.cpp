#include <bits/stdc++.h>

using namespace std;

//Depth First Search (DFS)
vector<int> adj[N];
bool vis[N];

void dfs(int s){
    vis[s] = true;
    for(int v : adj[s]){
        if(!vis[v]) dfs(v);
    }
}

//Flood Fill
int grid[N][N];
int colorGrid[N][N];
int row_num;
int col_num;
void floodfill(int row, int col, int clr){
	if((row < 0 || row >= row_num || col < 0 || col >= col_num) || colorGrid[row][col] != clr || visited[row][col]) return;

	visited[row][col] = true;

	floodfill(row, col + 1, clr);
	floodfill(row, col - 1, clr);
	floodfill(row - 1, col, clr);
	floodfill(row + 1, col, clr);
}


//1D Prefix Sums
int N;
int arr[N];
long long prefix[N + 1];
void psum(){
    for(int i = 1; i <= N; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }
}

//2D Prefix Sums
int M;
int arr2[M][M];
long long prefix2[M][M]
void psum(){
    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefix2[i][j] = arr2[i][j] + prefix2[i - 1][j] + prefix2[i][j - 1] - prefix2[i - 1][j - 1];
		}
	}
}

//Binary Search
bool f(int n){
    return n < 100;
}
int binarySearch(int low, int high){
    int mid;
    while(low < high){
        mid = (low + high + 1) / 2;
        if(f(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main(){

}