#include <ios>
#include <iomanip>
#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e9)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

int main()
{
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll cnt = 0;
    rep(r, 3001) {
        rep(g, 3001) {
            ll tmp = N - r * R - g * G;
            if (tmp >= 0 && tmp % B == 0) {
                cnt ++;
            }
        }
    }
    print(cnt);
    return 0;
}
