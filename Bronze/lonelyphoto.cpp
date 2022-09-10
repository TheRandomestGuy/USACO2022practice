#include <bits/stdc++.h>

using namespace std;

int N;
string line;

int main(){
    cin >> N >> line;

    int ans = 0;
    for(int i = 0; i < (int)line.size(); i++) {
        int g = 0;
        int h = 0;
        for(int j = i; j < (int)line.size(); j++) {
            if(line[j] == 'G') g++;
            else h++;
            if(g+h >= 3 && (g==1 || h==1)) ans++;
        }
    }
    cout << ans;
}