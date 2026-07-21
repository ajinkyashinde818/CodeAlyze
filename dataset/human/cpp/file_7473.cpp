#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <chrono>
#include <unordered_map>



using namespace std;

typedef long long int ll;
typedef int h_int;

#define REP(i, n) for(int i = 0; i < ( n ); ++i )
#define REPR(i, n) for(int i = ( n ); i >= 0; --i)
#define FOR(i, a, n) for(int i = ( a ); i < ( n ); ++i )
#define FORR(i, a, n) for(int i = ( n ); i >= ( a ); --i)

#define DOUT(x) cerr << #x << " = " << x << "\n";
#define COUT(x) cout << ( x ) << "\n";


signed main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n; cin >> n;
        vector<ll> a;
        a.resize(n);
        ll sum = 0;
        REP(i, n)
        {
                cin >> a[i];
                sum += a[i];
        }
        ll x = a[0];
        ll y = sum - x;
        ll m = abs(x - y);
        FOR(i, 1, n - 1)
        {
                x += a[i];
                y = sum - x;
                m = min(m, abs(x - y) );
        }
        std::cout << m << '\n';

        return 0;
}
