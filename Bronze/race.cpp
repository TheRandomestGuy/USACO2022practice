#include <bits/stdc++.h>
using namespace std;

int K, N;

int solve(int dist, int x) {
  int minspeed = x, ltravel = 0, rtravel = 0, time = 0;
  for(int i = 1; ; i++) {
    ltravel += i;
    time++;
    if(ltravel + rtravel >= dist) return time;
    if(i >= minspeed) {
      rtravel += i;
      time++;
      if(ltravel + rtravel >= dist) return time;
    }
  }
}

int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> K >> N;
    int x;
    for(int i = 0; i < N; i++){
        cin >> x;
        cout << solve(K, x) << endl;
    }

}