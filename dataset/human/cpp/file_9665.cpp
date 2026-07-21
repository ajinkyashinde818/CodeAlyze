#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include<complex>
#include <cassert>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n; i > 0; i--)
#define mod 1000000007
#define MOD 998244353
#define inf 1e20
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef complex<double> com;


int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, m) {
		cin >> b[i];
	}
	rep(i,n-m+1){
		rep(j, n - m + 1) {
			int cnt = 0;
			rep(k, m) {
				rep(l, m) {
					if (a[i + k][j + l] == b[k][l]) {
						cnt++;
					}
				}
			}
			if (cnt == m * m) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
//Ctrl+Aを使わない
