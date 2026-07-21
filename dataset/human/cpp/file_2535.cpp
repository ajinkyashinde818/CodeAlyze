#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int ans = 0;
	int m = 1000000007;
	bool p = false, z = false;
	for(auto i = 1; i <= n; ++i){
		int a;
		cin >> a;
		if(a < 0) p = !p;
		if(a == 0) z = true;
		a = abs(a);
		m = min(m, a);
		ans += a;
	}
	cout << (!z && p ? ans - m * 2 : ans) << endl;
	return 0;
}
