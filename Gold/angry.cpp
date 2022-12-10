#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> hay;



bool check(int fHay, int lHay, int r, vector<int> bales){
    int startExp = *lower_bound(bales.begin(), bales.end(), fHay - r);
    int endExp = *upper_bound(bales.begin(), bales.end(), lHay + r);
    if(startExp == bales[0] && startExp == bales[bales.size() - 1]) return true;
    if(startExp == fHay || endExp == lHay) return false;
    return check(startExp, endExp, r - 1, bales);
}

int first_true(int lo, int hi, int landing, vector<int> bales) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check( *lower_bound(bales.begin(), bales.end(), landing - mid), *upper_bound(bales.begin(), bales.end(), landing + mid), mid, bales)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
    cin >> N;
    int a;
    for(int i = 0; i < N; i++) {cin >> a; hay.push_back(a);}
    sort(hay.begin(), hay.end());
    int maxD = 0, landingSpot;
    for(int i = 1; i < N; i++){
        if(hay[i] - hay[i-1] > maxD) {maxD = hay[i] - hay[i-1];
        landingSpot = (hay[i] + hay[i-1])/2;}
    }

    int minR = maxD/2, maxR = (hay[hay.size()-1] - hay[0] + 1)/2;
    cout << first_true(minR, maxR, landingSpot, hay);
}