#include <bits/stdc++.h>
using namespace std;
template<class T> void read(T& x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9') {if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T,class U>void read(T&x,U&y){read(x),read(y);}
template<class T,class U,class V>void read(T&x,U&y,V&z){read(x),read(y),read(z);}
const long long maxn = 1e5 + 5, maxc = 1e14 + 5;
long long sum[maxn], sum2[maxn], x[maxn], v[maxn], opt[maxn], opt2[maxn];
int main()
{
	int n; long long c; read(n, c);
	for(int i = 1; i <= n; ++i)
		read(x[i], v[i]);
	long long ret = 0, pos = 0, ret2 = 0, pos2 = 0;
	for(int i = 1; i <= n; ++i) 
	{
		sum[i] += sum[i - 1] - x[i] + x[i - 1] + v[i];
		opt[i] = opt[i - 1];
		if(sum[i] > opt[i]) opt[i] = sum[i], pos = i;
	}
	x[n + 1] = c;
	for(int i = n; i; --i) 
	{
		sum2[i] += sum2[i + 1] - x[i + 1] + x[i] + v[i];
		opt2[i] = opt2[i + 1];
		if(sum2[i] > opt2[i]) opt2[i] = sum2[i], pos2 = i;
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans = max(ans, max(sum[i], sum[i] - x[i] + opt2[i + 1]));
	}
	for(int i = n; i; --i)
	{
		ans = max(ans, max(sum2[i], sum2[i] - (c - x[i]) + opt[i - 1]));
	}
	printf("%lld\n", ans);
	return 0;
}
