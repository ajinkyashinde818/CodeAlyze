#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

#include<thread>

using namespace std;

using ll = long long;


int main()
{
	int N;
	ll C;

	
	ll x[100002];
	ll v[100002];
	
	cin >> N >> C;

	for (int i = 1; i <= N; i++)
	{
		cin >> x[i] >> v[i];
	}

	ll dpL[100002] = { 0 };
	ll dpR[100002] = { 0 };

	ll eat = 0;

	for (int i = 1; i <= N; ++i)
	{
		eat += v[i];
		ll s = eat - x[i];

		if (dpL[i - 1] < s)
		{
			dpL[i] = s;
		}
		else
		{
			dpL[i] = dpL[i - 1];
		}
	}

	eat = 0;

	for (int i = N; i > 0; --i)
	{
		eat += v[i];
		ll s = eat - (C - x[i]);
		
		if (dpR[i + 1] < s)
		{
			dpR[i] = s;
		}
		else
		{
			dpR[i] = dpR[i + 1];
		}
	}

	ll ans = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (ans < dpL[i]) { ans = dpL[i]; }

		ll s = dpL[i] - x[i] + dpR[i + 1];

		if (ans < s) { ans = s; }
	}

	for (int i = N; i > 0; --i)
	{
		if (ans < dpR[i]) { ans = dpR[i]; }

		ll s = dpR[i] - (C - x[i]) + dpL[i - 1];
		
		if (ans < s) { ans = s; }
	}

	cout << ans << endl;

	return 0;
	
}
