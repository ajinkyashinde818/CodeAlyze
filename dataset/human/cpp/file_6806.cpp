#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
#define reps( i, n ) for ( ll i = 1; i <= (ll)( n ); ++i )
#define rrep( i, n ) for ( ll i = (ll)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( ll i = (ll)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }


int main()
{
	ll n; cin >> n;
	vector<ll> a( n ), b( n );
	map<ll, ll> ma, mb;
	rep( i, n ) { cin >> a[i]; ma[a[i]]++; }
	rep( i, n ) { cin >> b[i]; mb[b[i]]++; }
	reps( i, n ) if ( ma[i] + mb[i] > n ) { cout << "No" << endl; return ( 0 ); }

	vector<ll> c( n + 1 ), d( n + 1 );
	reps( i, n )
	{
		c[i] = c[i - 1] + ma[i];
		d[i] = d[i - 1] + mb[i];
	}

	ll sft = -1;
	reps( i, n ) chmax( sft, c[i] - d[i - 1] );

	cout << "Yes" << endl;
	rotate( b.begin(), b.begin() + ( n - sft ), b.end() );
	rep( i, n ) cout << b[i] << " \n"[i == n - 1];

	return ( 0 );
}
