#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<long long> a;

int gcd(long long a, long long b){
    if(a == 0) return b;
    return gcd(b % a, a)
}

int main() {
    cin >> T;
    
}