#include <bits/stdc++.h>
 
using namespace std;
 
template <class T>
using lim = numeric_limits<T>;
 
typedef long long ll;
typedef long double ld;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	ll a[n];
	
	int count = 0;
	ll total = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if (a[i] < 0){
			count++;
		}
		a[i] = abs(a[i]);
		total += a[i];
	}
	
	if (count%2){
		ll small = lim<ll>::max();
		for (int i = 0; i < n; i++){
			if (a[i] < small) small = a[i];
		}
		
		total -= 2*small;
	}
	
	cout << total << endl;
}
