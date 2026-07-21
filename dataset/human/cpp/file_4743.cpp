#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;

LL inf = 1000000000000;
LL mod = 1000000007;


int main()
{
	LL n, r;
	cin >> n >> r;

	if (n >= 10) {
		cout << r << "\n";
	}
	else {
		cout << r - 100*(n-10) << "\n";
	}
	
}
