#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<time.h>
#include<cstdlib>
using namespace std;
#define ll long long
#define inf (999999999)
#define fi first
#define se second
#define MOD 1e9+7
#define PI acos(-1.0)
//--------------------------------------------------------------------------------------------------//
int n;
int a[1234567];
ll s[1234567];
int main() {
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	ll ans = 1e18;
	for (int i = 0; i < n-1; i++) {
		//cout << s[i] << endl;
		//cout << sum - s[i] << endl;
		ans = min(ans, abs(s[i] - (sum - s[i])));
	}
	cout << ans << endl;
}
