#include <iostream>
#include <string>
using namespace std;

long long n, l = 0, r = 0, m = 1;
string s;
bool f = 0;

const long long T = 1000000007;

int main()
{	
	cin >> n >> s;

	for (long long i = 0; i < n * 2; i++) {
		if (((l - r) % 2 == 0 && s[i] == 'B') || ((l - r) % 2 == 1 && s[i] == 'W')) {
			l++;
			m = m * (l - r) % T;
		}
		else
			r++;

		if (r > l || l > n) {
			f = 1;
			break;
		}
	}

	if(f)
		cout << 0 << endl;
	else {
		for (long long i = 2; i <= n; i++)
			m = m * i % T;

		cout << m << endl;
	}

	return 0;
}
