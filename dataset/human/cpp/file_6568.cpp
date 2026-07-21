#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	ll r = 1, t = 0;
	bool now = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (now)s[i] = 'B' + 'W' - s[i];
		if (s[i] == 'W')r = r*t%mod, t--, now = !now;
		else t++, now = !now;
	}
	if (t != 0)r = 0;
	for (int i = 1; i <= num; i++)r = r*i%mod;
	printf("%lld\n", r);
}
