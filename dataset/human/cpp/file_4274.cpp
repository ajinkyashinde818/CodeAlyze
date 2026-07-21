#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 7;

inline int R()
{
	char ch = getchar();
	int rt = 0;
	bool isn = false;
	for ( ; ch < '0' || ch > '9'; ch = getchar() )
		isn = ch == '-' ? true : isn;
	for ( ; ch >= '0' && ch <= '9'; ch = getchar() )
		rt = rt * 10 + ch - '0';
	return isn ? -rt : rt;
}

int a[MAXN], b[MAXN], num[MAXN << 1], sa[MAXN], sb[MAXN], u[MAXN << 1];
map<int, int> hs;

bool Cmp ( int t1, int t2 )
{
	return t1 < t2;
}

int f[MAXN << 1];

int Fnd ( int nf )
{
	return f[nf] == nf ? nf : f[nf] = Fnd ( f[nf] );
}

int main()
{
//	freopen ( "duliu.in", "r", stdin );
//	freopen ( "duliu.out", "w", stdout );
	int n = R(), ns = 0, nn = 0, nun = 0;
	for ( int i = 1; i <= n; ++i )
		a[i] = R(), ns ^= a[i], num[++nn] = a[i], sa[i] = a[i];
	sa[n + 1] = ns, num[++nn] = ns;
	int bs = 0, ans = 0;
	for ( int i = 1; i <= n; ++i )
		b[i] = R(), num[++nn] = b[i], bs ^= b[i], sb[i] = b[i];
	sb[n + 1] = bs, num[++nn] = bs;
	sort ( sa + 1, sa + n + 2, Cmp ), sort ( sb + 1, sb + n + 2, Cmp );
	for ( int i = 1; i <= n + 1; ++i )
		if ( sa[i] != sb[i] )
		{
			puts ( "-1" );
			return 0;
		}
	sort ( num + 1, num + nn + 1, Cmp );
	num[0] = -1;
	for ( int i = 1; i <= nn; ++i )
		if ( num[i] != num[i - 1] )
			hs[num[i]] = ++nun;
	ns = hs[ns];
	for ( int i = 1; i <= nun; ++i )
		f[i] = i;
	for ( int i = 1; i <= n; ++i )
		a[i] = hs[a[i]], b[i] = hs[b[i]];
	for ( int i = 1; i <= n; ++i )
		if ( a[i] != b[i] )
		{
			int fa = Fnd ( a[i] ), fb = Fnd ( b[i] );
			if ( fa != fb )
				f[fa] = fb;
			++ans;
		}
	for ( int i = 1; i <= n; ++i )
		if ( a[i] != b[i] )
		{
			int fa = Fnd ( a[i] ), fb = Fnd ( b[i] );
			if ( !u[fa] )
				u[fa] = true, ++ans;
			if ( !u[fb] )
				u[fb] = true, ++ans;
		}
	if ( u[Fnd ( ns )] )
		--ans;
	printf ( "%d\n", ans );
	return 0;
}
