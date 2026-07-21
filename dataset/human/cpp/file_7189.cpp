#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	ll n, sum = 0;
	ll v[200020];
	cin >> n;
	v[0] = 0;
	for (int i = 0;i < n;i++) {
		ll a;
		cin >> a;
		sum += a;
		v[i + 1] = a + v[i];
	}
	ll maxx = 10000000000;
	for (int i = 1;i < n;i++) {
		maxx = min(abs(sum - v[i] - v[i]), maxx);
	}
	cout << maxx << endl;
}
