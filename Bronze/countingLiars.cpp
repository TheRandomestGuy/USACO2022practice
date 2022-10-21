#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int N;
    pair<string, int> cows[1000];

    cin >> N;

    string a;
    int b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        cows[i].first = a;
        cows[i].second = b;
    }
}