#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include <limits>
#include <numeric>
#include <type_traits>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<long long int> a(n);
	int f = 0;
	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i]<0)
		{
			f++;
		}
		ans += abs(a[i]);
		a[i] = abs(a[i]);
	}
	
	if (f % 2 == 0)
	{
		cout << ans << endl;
	}
	else
	{
		sort(a.begin(), a.end());
		cout << ans - 2 * (abs(a[0]));
	}

	
}
