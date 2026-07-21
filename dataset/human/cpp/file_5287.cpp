/*

	Code by : Ivan Zanov
	Competitione 2020
	First Competition

*/
#include <chrono>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <assert.h>
#include <cmath>
#include <algorithm>
#include <complex>
#include <deque>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <sstream>
#include <exception>
#include <functional>
#include <cstring>
#include <cstdlib>
using namespace std;
using namespace std :: chrono;
#define lowbit(x) ((x)&((x)^((x)-1)))
#define max(a,b) (a<b?b:a)
#define IOS ios_base::sync_with_stdio(0);
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define INF (int)1e9
#define EPS (int)1e-9
#define bit_count __builtin_popcount
#define gcd __gcd
#define max3(a, b, c) max(a, max(b,c))
#define min3(a, b, c) min(a, min(b,c))
#define abs(x) (x < 0 ? (-x) : x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
inline void set_bit(int & n, int b) { n |= (1 << (int) b); }
inline void unset_bit(int & n, int b) { n &= ~(1 << (int) b); }
inline bool check_bit(int n, int pos) { return ( n & (1 << (pos))); }
inline ll lcm(ll a, ll b){ return (a * b / gcd(a,b));}
inline ll square(ll a){return (a * a);}
int main() {
	int n, r;
	cin>>n>>r;
	if(n >= 10)
		cout<<r<<endl;
	else
	{
		cout<<r + 100 * (10 - n)<<endl;
	}
	return 0;
	/*auto start = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<fixed<<setprecision(3)<<duration.count() * 1e-6<<endl;*/
    return 0;
}
