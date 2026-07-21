#include <iostream>

using namespace std;
long long x[100010],v[100010],ret1[100010],ret2[100010],n,c,ans = 0,ret,mx;
int main(){
	int i;
	cin >> n >> c;
	for(i=0;i<n;i++){
		cin >> x[i] >> v[i];
	}
	ret = 0; mx = 0;
	for(i=0;i<n;i++){
		ret += v[i];
		mx = max(mx,ret - x[i]);
		ret1[i] = mx;
	}
	ans = mx;
	ret = 0; mx = 0;
	for(i=n-1;i>=0;i--){
		ret += v[i];
		mx = max(mx,ret - (c - x[i]));
		ret2[i] = mx;
	}
	ans = max(mx,ans);
	ret = 0;
	ret2[n] = 0;
	for(i=0;i<n;i++){
		ret += v[i];
		ans = max(ans,ret - 2*x[i] + ret2[i+1]);
	}
	ret = 0;
	for(i=n-1;i>=1;i--){
		ret += v[i];
		ans = max(ans,ret - 2*(c - x[i]) + ret1[i-1]);
	}
	cout << ans << endl;
}
