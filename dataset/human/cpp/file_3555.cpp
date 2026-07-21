#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n, ans = 0, cnt = 0;
	cin >> n;
	long long a[100001];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans += abs(a[i]);
		if(a[i] < 0)
		{
			cnt++;
		}
		a[i] = abs(a[i]);
	}
	sort(a,a+n);
	if(cnt % 2)
		ans -= 2*a[0];
	cout << ans << endl;
}
