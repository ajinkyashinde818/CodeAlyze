#include <string>
#include <algorithm>
#include <vector> 
#include <math.h>
#include <iostream>
using namespace std;
long long mod = 1000000000 + 7;



int main()
{
	int n;
	cin >> n;
	vector<long long> a;
	int flag = 1;
	long long m = 9999999999;
	for (int i = 0; i < n; i++) {
		long long in;
		
		cin >> in;
		if (in < 0) {
			flag = flag * (-1);
			in = in * (-1);
			
		}
		m = min(m, in);
		a.push_back(in);
	}
	long long ans = 0;
	if (flag == 1) {
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
		ans = ans - 2 * m;
	}

	cout << ans << endl;
	return 0;

}
