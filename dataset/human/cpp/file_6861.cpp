#include <bits/stdc++.h>

using namespace std;

long long int cnt[200005];
long long int cnt2[200005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t;
	vector <int> a,b;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		a.push_back(t);
		cnt[t]++;
	}

	for(int i=0;i<n;i++)
	{
		cin >> t;
		b.push_back(t);
		cnt2[t]++;
	}

	for(int i=1;i<=n;i++)
	{
		if(cnt[i] + cnt2[i] > n)
		{
			cout << "No" << '\n';
			return 0;
		}
	}

	cout << "Yes" << '\n';

	long long int x = 0;

	for(int i=1;i<=n;i++)
	{
		cnt[i] += cnt[i-1];
		cnt2[i] += cnt2[i-1];
		x = max(x,cnt[i] - cnt2[i-1]);
	}

	for(int i=0;i<n;i++)
	{
		int idx = i + n - x;
		idx%=n;
		cout << b[idx] << ' ';
	}
	cout << '\n';

	return 0;
}
