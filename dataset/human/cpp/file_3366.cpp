#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/

	int n, cnt = 0;
	cin >> n;

	long long a[n], sum = 0, mini = LLONG_MAX;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += abs(a[i]);
		if(a[i] < 0)
			cnt++;
		mini = min(mini, abs(a[i]));
	}
	if(cnt % 2)
		sum = sum - 2 * mini;
	cout << sum << endl;
	return 0;
}
