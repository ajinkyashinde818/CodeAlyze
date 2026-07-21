#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
ll n, z, s = 1, num;
string a;
int main()
{
	ll i;
	cin >> n;
	cin >> a;
	if (a[0] == 'W') {
		cout << 0 << endl;
		return 0;
	}
	z = 1;
	for (i = 1; i < a.size(); i++) {
		if (a[i] == 'B') num = 1;
		else num = 0;
		if (z % 2 == num) {
			if (z == 0) {
				cout << 0 << endl;
				return 0;
			}
			s = (s * z) % M;
			z--;
		} else z++;
	}
	if (z != 0) {
		cout << 0 << endl;
		return 0;
	}
	for (i = 1; i <= n; i++) s = (s * i) % M;
    cout << s << endl;
    return 0;
}
