#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n], m = (int)1e9, count = 0;
	long long sum = 0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		m = min(m, abs(a[i]));
		if(a[i] < 0) count++;
		sum += abs(a[i]);
	}
	if(count%2)
		sum -= 2*m;
	cout << sum << "\n";
	return 0;
}
