#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000;

int n; ll c, ans = 0;

ll f[N][2], g[N][2];
// f[i][0] = sum, f[i][1] = dis;

inline void ck_max( ll &a, ll b ) { if( a < b ) a = b; }

struct tSushi {
	ll x, v;
} s[N];

struct deleteable_heap {
	priority_queue <ll> q1, q2;
	
	inline void push( ll val ) { q1.push( val ); }
	inline void check() {
		if( q1.empty() || q2.empty() ) 	
			return;
			 
		while( q1.top() == q2.top() ) {
			q1.pop(), q2.pop();
			if( q1.empty() || q2.empty() )
				break;
		}
	}
	inline void erase( ll val ) { q2.push( val ); }
	inline ll top() { check(); return q1.top(); }
} heap_1, heap_2;

int main()
{
	memset( f, 0, sizeof( f ) );
	memset( g, 0, sizeof( g ) );
	
	scanf( "%d%lld", &n, &c );
	for( int i = 1; i <= n; i ++ )
		scanf( "%lld%d", &s[i].x, &s[i].v );
	
	for( int i = 1; i <= n; i ++ )
		f[i][0] = f[i-1][0] + s[i].v, f[i][1] = s[i].x;
	for( int i = n; i >= 1; i -- )
		g[i][0] = g[i+1][0] + s[i].v, g[i][1] = c - s[i].x;
		
	for( int i = 1; i <= n; i ++ )
		ck_max( ans, f[i][0] - f[i][1] ), 
		ck_max( ans, g[i][0] - g[i][1] );
		
//	for( int i = 1; i <= n; i ++ )
//		printf( "f0:%lld, f1:%lld, g0:%lld, g1:%lld\n", f[i][0], f[i][1], g[i][0], g[i][1] );
		
	for( int i = 1; i <= n; i ++ )
		heap_1.push( g[i][0] - g[i][1] ),
		heap_2.push( g[i][0] - g[i][1] * 2 );
	
	for( int i = 1; i < n; i ++ )
	{
		heap_1.erase( g[i][0] - g[i][1] );
		heap_2.erase( g[i][0] - g[i][1] * 2 );
		ll tmp_1 = heap_1.top() + f[i][0] - f[i][1] * 2;
		ll tmp_2 = heap_2.top() + f[i][0] - f[i][1];
		ck_max( ans, tmp_1 );
		ck_max( ans, tmp_2 ); 
	}
	
	printf( "%lld\n", ans );
	
	return 0;
}
