#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n, mini = MOD, coun;
	bool muteki = false;
	ll ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] < 0) coun++;
		if (a[i] == 0) muteki = true;
	}
	if (muteki || coun%2 == 0){
		for (auto x : a){
			ans += abs(x);
		}
	}else{
		for (int i = 0; i < n; i++){
			a[i] = abs(a[i]);
		}
		sort(a.begin(), a.end());
		ans -= a[0];
		for (int i = 1; i < n; i++){
			ans += a[i];
		}
	}
	cout << ans << endl;
 	return 0;
}
