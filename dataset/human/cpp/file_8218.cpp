#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod = 1000000007;
ll gcd(ll a, ll b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
ll a[202020];
int main()
{
	int num;
	scanf("%d", &num);
	ll s = 0;
	for (int i = 0; i < num; i++)scanf("%lld", &a[i]), s += a[i];
	ll n = 0, mini = 1000000000000000000LL;
	for (int i = 0; i < num - 1; i++)
	{
		n += a[i];
		mini = min(mini, abs(s - n - n));
	}
	printf("%lld\n", mini);
}
