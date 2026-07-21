#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
	}

	long long ans = 1e18;
	long long x = 0;
	long long y;
	for(int i = 0; i < n - 1; i++){
		x += v[i];
		y = sum - x;
		ans = min(ans, abs(x - y));
	}
	cout << ans << endl;


}
