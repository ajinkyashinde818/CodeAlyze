#include                            <iostream>
#include							<list>
#include                            <stdio.h>
#include                            <math.h>
#include                            <string.h>
#include                            <time.h>
#include                            <stdlib.h>
#include                            <string>
#include                            <bitset>
#include                            <vector>
#include                            <set>
#include                            <map>
#include                            <queue>
#include                            <algorithm>
#include                            <sstream>
#include                            <stack>
#include                            <iomanip>
#include                            <numeric>
#include							<unordered_map>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_pbds;
using namespace std;
typedef
tree <
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update >
set_t;

using namespace                     std;
#define MOD                         1000000007
#define int                         int64_t
#define baba_shiv                   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mpii                        map<int,int>
#define pb                          push_back
#define mkp                         make_pair
#define all(x)                      x.begin(),x.end()
#define allr(x)                     x.rbegin(),x.rend()
#define ub(v,x)                     upper_bound(all(v),x)
#define lb(v,x)                     lower_bound(all(v),x)
#define bs(v,x)                     binary_search(all(v),x)
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    (((a*b))/__gcd(a,b))
#define vi                          vector<int>
#define pii                         pair<int,int>
#define vpii                        vector<pii>
#define vs                          vector<string>
#define ff                          first
#define ss                          second

#define double						long double
/***********************************************************************************************************************/
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	typename vector< T > :: const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	typename set< T > :: const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	typename map< F , S >::const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
	}
	return os << "]";
}

#define deb(x) cerr<< #x << " = " << x << endl;

/***********************************************************************************************************************/

signed main()
{
	baba_shiv;
	int n, r;
	cin >> n >> r;
	if (n >= 10)
	{
		cout << r << endl;
		return 0;
	}
	int ir = r + 100 * (10 - n);
	cout << ir << endl;
}
