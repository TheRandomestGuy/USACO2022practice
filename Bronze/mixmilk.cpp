#include <bits/stdc++.h>

using namespace std;

pair<int, int> a, b, c;

int pourAmount(pair<int, int> giver, pair<int, int> taker){
    int ans = giver.second;
    int placeholder = taker.second;
    taker.second = min(taker.first, taker.second + giver.second);
    giver.second = max(0, giver.second - taker.first + placeholder);
    ans -= giver.second;
    return ans;
}

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    int pa = pourAmount(a,b);
    a.second -= pa;
    b.second += pa; 
    for(int i = 0; i < 33; i++){
    pa = pourAmount(b,c);
    b.second -= pa;
    c.second += pa; 
    pa = pourAmount(c,a);
    c.second -= pa;
    a.second += pa; 
    pa = pourAmount(a,b);
    a.second -= pa;
    b.second += pa; 
    }

    cout << a.second << endl << b.second << endl << c.second;
}