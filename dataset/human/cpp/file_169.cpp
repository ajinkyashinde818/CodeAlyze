#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 10000000000000000;
const int mod = 1000000007;
int test[12345678], kari[345678], aa[12345678];
signed main() {
	int n, a, b, c, ans = 0; cin >> a >> b >> c >> n;
	for (int h = 0; h <= 3000; h++) {
		for (int i = 0; i <= 3000; i++) {
			if (n - (h * a) - (i * b) >= 0 && (n - (h * a) - (i * b)) % c == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	cin >> n; return 0;
}
