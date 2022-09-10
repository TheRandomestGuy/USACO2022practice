#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);

  int n = 0;
  cin >> n;
  pair<int, int> milkTimeShared[n];
  for (int i = 0; i < n; i++)
    cin >> milkTimeShared[i].second >> milkTimeShared[i].first;

  sort(milkTimeShared, milkTimeShared + n);
  
  int pointer1 = 0, pointer2 = n - 1, answer = 0;
  int amount;
  while (pointer1 < pointer2) {
    amount = min(milkTimeShared[pointer1].second, milkTimeShared[pointer2].second);
    milkTimeShared[pointer1].second -= amount;
    milkTimeShared[pointer2].second -= amount;
    
    answer = max(milkTimeShared[pointer1].first + milkTimeShared[pointer2].first, answer);

    if (milkTimeShared[pointer1].second == 0)
      pointer1++;
    if (milkTimeShared[pointer2].second == 0)
      pointer2--;
  }

  cout << answer;
}