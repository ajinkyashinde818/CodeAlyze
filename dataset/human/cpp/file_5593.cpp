#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 +7;
const ll MAXN = 1e6 + 5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,r;
	cin >> n >> r;
	cout << (n >= 10 ? r : r + 100 * (10 - n));
	return 0;
}
