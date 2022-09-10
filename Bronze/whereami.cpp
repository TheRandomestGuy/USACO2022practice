#include <iostream>
using namespace std;

int n;
string sequence;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  cin >> n >> sequence;

  int answer = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (sequence.find(sequence.substr(j, i)) != sequence.rfind(sequence.substr(j, i))) {
        answer = i+1;
      }
    }
  }
  cout << answer;
}