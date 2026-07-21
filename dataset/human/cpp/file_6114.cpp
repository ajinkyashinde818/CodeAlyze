#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;

Int ans = 0;
Int gobackr[108000];
Int gobackl[108000];
Int gor[108000];
Int gol[108000];
Int x[108000];
Int v[108000];
Int n, c;
int main(){
	cin >> n >> c;
	ans -= c;
	for(Int i = 0;i < n;i++){
		cin >> x[i]>> v[i];
		ans += v[i];
	}

	ans = max(ans, 0LL);
	Int sum = 0;
	for(Int i = 0;i < n;i++){
		sum += v[i];
		gobackr[i+1] = max(gobackr[i], sum - 2 * x[i]);
		gor[i+1] = max(gor[i], sum - x[i]);
	}
	sum = 0;
	for(Int i = n-1;i >= 0;i--){
		sum += v[i];
		gobackl[i] = max(gobackl[i+1], sum - 2 * (c-x[i]));
		gol[i] = max(gol[i+1], sum - (c-x[i]));
	}

	for(Int i = 0;i <= n;i++){
		ans = max(ans, gobackr[i] +gol[i]);
		ans = max(ans, gobackl[i] +gor[i]);
	}
	cout << ans << endl;
	return 0;
}
