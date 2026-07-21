#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll ans,n,c;
	cin >> n;
	vector <ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ans=0;
	sort(a.begin(),a.end());
	// for(int i=0;i<n;i++){
	// 	cout << a[i] << endl;
	// }
	for(int i=0;i<n-1;i++){
		if(a[i]<=0 && a[i+1]<=0){
			a[i]=-a[i];
			a[i+1]=-a[i+1];
			}
		else if(a[i]<=0 && a[i+1]>=0){
			if(-a[i]>=a[i+1]){
				a[i] = -a[i];
				a[i+1] = -a[i+1];
			}
		}

	}
	for(int i=0;i<n;i++){
		ans += a[i];
	}
	cout << ans;
	cin >> n;
}
