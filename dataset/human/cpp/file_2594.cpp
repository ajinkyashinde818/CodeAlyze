#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,ans=0,sum=0;
	cin >> n;
	long long x[n];
	for(int i = 0 ; i < n ; i += 1){
		cin >> x[i];
		if(x[i] <= 0){
			sum ^= 1;
		}
	}
	if(sum){
		long long maxi = 1000000000;
		for(int i = 0 ; i < n ; i += 1){
			ans += abs(x[i]);
			maxi = min(maxi,abs(x[i]));
		}
		cout << ans - 2*maxi;
	}else{
		for(int i = 0 ; i < n ; i += 1){
			ans += abs(x[i]);
		}
		cout << ans;
	}
}
