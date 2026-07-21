#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2e5+10;
int n;
int a[SIZE], b[SIZE], l[SIZE], r[SIZE];

inline int read()
{	
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
	return x;
}

int main()
{
	int l = SIZE, r = 0, c = 0;
	n=read();
	for (int i = 1; i <= n; ++i) a[i]=read();
	for (int j = 1; j <= n; ++j) b[j]=read();
	for (int i = 1; i <= (n>>1);++i) swap(b[i], b[n-i+1]);
	for (int i = 1; i <= n; ++i)
		if (a[i] == b[i]) { r = i; if (l > n) l = i;}
	for (int i = 1; i <= n; ++i)
		if (a[i] != a[r] && b[i] != a[r]) ++c;
	if (c < r - l + 1) printf("No\n");
	else
	{
		printf("Yes\n");
		for (int i = 1; i <= n; ++i)
		{
			if (l > r) break;
			if (a[i] != a[l] && b[i] != a[l]) swap(b[i], b[l++]);
		}
		for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
	}
	return 0;
}
