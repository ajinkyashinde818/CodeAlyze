#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;

	ll a[n];
	ll abs_min = 1000000001;
	int minus_cnt = 0;
	ll ans=0;

	for(int i=0; i<n; i++){
		cin >> a[i];

		if(a[i] < 0) 
			minus_cnt++;

		if(abs(a[i]) < abs_min)
			abs_min = abs(a[i]);

		ans += abs(a[i]);
	}

	if(minus_cnt % 2 == 1)
		ans -= 2*abs_min;
	
	cout << ans << endl;
	return 0;
}
