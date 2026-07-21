#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

long long xl[100005], xr[100005],vl[100005],vr[100005],c,ls[100005],rs[100005],cleft[100005],cright[100005],lmax[100005],rmax[100005];
int n;
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> xl[i] >> vl[i];
		xr[n + 1 - i] = c - xl[i];
		vr[n + 1 - i] = vl[i];
	}
	for (int i = 1; i <= n; i++) {
		ls[i] = ls[i - 1] + vl[i];
		rs[i] = rs[i - 1] + vr[i];
	}

	for (int i = 0; i <= n; i++) {
		cleft[i] = ls[i] - xl[i];
		cright[i] = rs[i] - xr[i];
	}
	//for (int i = 0; i <= n; i++) {
	//	cout << xr[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i <= n; i++) {
	//	cout << cleft[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i <= n; i++) {
	//	cout << cright[i] << " ";
	//}
	long long v = 0;
	//cout << " l max" << endl;
	for (int i = 0; i <= n; i++) {
		if (v < cleft[i]) {
			v = cleft[i];
		}
		lmax[i] = v;
	//	cout << v << " ";
	}
	//cout << endl;
	v = 0;
	for (int i = 0; i <= n; i++) {
		if (v < cright[i]) {
			v = cright[i];
		}
		rmax[i] = v;
	//	cout << v << " ";
	}
	//cout << endl << endl;
	long long ans = max(rmax[n], lmax[n]);
	for (int i = 1; i <= n; i++) {
		ans = max(ans, cleft[i] - xl[i] + rmax[n - i]);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, cright[i] - xr[i] + lmax[n - i]);
	}
	cout << ans << endl;

	return 0;
}
