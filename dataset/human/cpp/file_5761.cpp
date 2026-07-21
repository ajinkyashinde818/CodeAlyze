#include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N = 300000;
     
    int n, cnt = 0, son[N][2]; ll l;
    string s;
     
    ll dfs( int u, int dep )
    {
    ll x = l - dep + 1;
    if( !u && dep ) return x & -x;
    return dfs( son[u][0], dep+1 ) ^ dfs( son[u][1], dep+1 );
    }
     
    int main()
    {
    scanf( "%d%lld", &n, &l );
    for( int i = 1; i <= n; i ++ )
    {
    cin>> s;
    int u = 0, len = s.size();
    for( int j = 0; j < len; j ++ )
    {
    int w = s[j] - '0';
    if( !son[u][w] )
    son[u][w] = ++ cnt;
    u = son[u][w];
    }
    }
    if( dfs( 0, 0 ) ) puts( "Alice" );
    else puts( "Bob" );
    return 0;
    }
