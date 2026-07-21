#include <bits/stdc++.h>
#include <iomanip>	// fixed setprecision
#include <numeric>	// accumulate
using namespace std;
using ll = long long;
using ld = long double;

int main() {
	cout << fixed << setprecision(10);	// https://qiita.com/a4rcvv/items/05febcf410c51009a29a

	int n, r;
	cin >> n >> r;

	if (n >= 10)
	{
		cout << r << endl;
	}
	else
	{
		cout << (((10 - n) * 100) + r) << endl;
	}

	return 0;
}
