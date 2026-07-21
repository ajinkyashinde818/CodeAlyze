#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int n;
	int i;
	long long X=0, x = 0, ans = 1000000000000000000LL;
	cin >> n;
	vector<long long> a(n);
	for(i=0; i<n; i++){
		cin >> a[i];
		X += a[i];
	}
	for(i =0; i<n; i++){
		x += a[i];
		if(i + 1 < n){
			ans = min(ans, abs(X - 2*x));
		}
	}

	cout << ans;

	cout << '\n';
	return 0;
}
