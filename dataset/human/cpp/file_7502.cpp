#include<bits/stdc++.h>

using namespace std;

long long n, a[200000], X, x;
long long ans = 10000000000000000LL;

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		X += a[i];
	}
	for(int i = 0; i < n - 1; ++i){
		x += a[i];
		ans = min(ans, abs(X-2*x));
	}
	cout << ans << endl;
}
