#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;

int main() {
	ll n, r;
	cin >> n >> r;
	if (n >= 10) { cout << r << endl; }
	else cout << 100 * (10 - n) + r << endl;
	return 0;
}
