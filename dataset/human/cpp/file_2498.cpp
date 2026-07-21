#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<iomanip>
#include<vector>
//#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;


int main() {
	ll n, a[100010], sum = 0,c=0;
	bool f;

	cin >> n;
	for (int i = 0; i < (n); i++)cin >> a[i];

	for (int i = 0; i < n; i++)if (a[i] < 0)c++;


	if (c % 2)f = true;
	else f = false;
	for (int i = 0; i < (n); i++) {
		sum += abs(a[i]);
		a[i] = abs(a[i]);
	}
	
	sort(a, a + n);
	if (f)sum -= 2*abs(a[0]);
	cout << sum << endl;

}
